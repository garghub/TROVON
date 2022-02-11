static inline T_1 F_1 ( T_1 V_1 )
{
T_1 V_2 = V_1 ;
V_2 ^= ( V_1 >> 24 ) ;
return V_2 & ( V_3 - 1 ) ;
}
int F_2 ( void )
{
struct V_4 * V_5 ;
int V_6 ;
F_3 ( & V_7 ) ;
V_6 = V_8 ;
while ( V_6 ) {
V_5 = F_4 ( sizeof( * V_5 ) , V_9 ) ;
if ( ! V_5 )
goto V_10;
F_5 ( & V_5 -> V_11 , & V_7 ) ;
V_5 -> V_12 = V_13 ;
V_5 -> V_14 = V_15 ;
F_6 ( & V_5 -> V_16 ) ;
V_6 -- ;
}
V_17 = F_7 ( V_3 , sizeof( struct V_18 ) , V_9 ) ;
if ( ! V_17 )
goto V_10;
V_19 = 0 ;
return 0 ;
V_10:
F_8 ( V_20 L_1 ) ;
F_9 () ;
return - V_21 ;
}
void F_9 ( void )
{
struct V_4 * V_5 ;
while ( ! F_10 ( & V_7 ) ) {
V_5 = F_11 ( V_7 . V_22 , struct V_4 , V_11 ) ;
if ( V_5 -> V_12 == V_23 && V_5 -> V_14 == V_24 )
F_12 ( V_5 -> V_25 . V_26 ) ;
F_13 ( & V_5 -> V_11 ) ;
F_12 ( V_5 ) ;
}
V_19 = 1 ;
F_12 ( V_17 ) ;
V_17 = NULL ;
}
static void
F_14 ( struct V_4 * V_5 )
{
F_15 ( & V_5 -> V_11 , & V_7 ) ;
}
static void
F_16 ( struct V_4 * V_5 )
{
F_17 ( & V_5 -> V_16 ) ;
F_18 ( & V_5 -> V_16 , V_17 + F_1 ( V_5 -> V_27 ) ) ;
}
int
F_19 ( struct V_28 * V_29 )
{
struct V_30 * V_31 ;
struct V_18 * V_32 ;
struct V_4 * V_5 ;
T_2 V_1 = V_29 -> V_33 ;
T_1 V_34 = V_29 -> V_35 ,
V_36 = V_29 -> V_37 ,
V_38 = V_29 -> V_39 ;
unsigned long V_40 ;
int type = V_29 -> V_41 ;
int V_42 ;
V_29 -> V_43 = NULL ;
if ( V_19 || type == V_15 ) {
V_44 . V_45 ++ ;
return V_46 ;
}
F_20 ( & V_47 ) ;
V_42 = V_46 ;
V_32 = & V_17 [ F_1 ( V_1 ) ] ;
F_21 (rp, hn, rh, c_hash) {
if ( V_5 -> V_12 != V_13 &&
V_1 == V_5 -> V_27 && V_38 == V_5 -> V_48 &&
V_34 == V_5 -> V_49 && V_36 == V_5 -> V_50 &&
F_22 ( V_51 , V_5 -> V_52 + 120 * V_53 ) &&
memcmp ( ( char * ) & V_29 -> V_54 , ( char * ) & V_5 -> V_55 , sizeof( V_5 -> V_55 ) ) == 0 ) {
V_44 . V_56 ++ ;
goto V_57;
}
}
V_44 . V_58 ++ ;
{
int V_59 = 0 ;
F_23 (rp, &lru_head, c_lru) {
if ( V_5 -> V_12 != V_60 )
break;
if ( V_59 ++ > V_8 ) {
F_8 ( L_2 ) ;
V_19 = 1 ;
goto V_61;
}
}
}
if ( & V_5 -> V_11 == & V_7 ) {
static int V_62 ;
F_8 ( V_63 L_3 ) ;
if ( ++ V_62 > 5 ) {
F_8 ( V_63 L_4 ) ;
V_19 = 1 ;
}
goto V_61;
}
V_29 -> V_43 = V_5 ;
V_5 -> V_12 = V_60 ;
V_5 -> V_27 = V_1 ;
V_5 -> V_48 = V_38 ;
memcpy ( & V_5 -> V_55 , F_24 ( V_29 ) , sizeof( V_5 -> V_55 ) ) ;
V_5 -> V_49 = V_34 ;
V_5 -> V_50 = V_36 ;
V_5 -> V_52 = V_51 ;
F_16 ( V_5 ) ;
if ( V_5 -> V_14 == V_24 ) {
F_12 ( V_5 -> V_25 . V_26 ) ;
V_5 -> V_25 . V_26 = NULL ;
}
V_5 -> V_14 = V_15 ;
V_61:
F_25 ( & V_47 ) ;
return V_42 ;
V_57:
V_40 = V_51 - V_5 -> V_52 ;
V_5 -> V_52 = V_51 ;
F_14 ( V_5 ) ;
V_42 = V_64 ;
if ( V_5 -> V_12 == V_60 || V_40 < V_65 )
goto V_61;
V_42 = V_46 ;
if ( ! V_29 -> V_66 && V_5 -> V_67 )
goto V_61;
switch ( V_5 -> V_14 ) {
case V_15 :
break;
case V_68 :
F_26 ( & V_29 -> V_69 . V_70 [ 0 ] , V_5 -> V_71 ) ;
V_42 = V_72 ;
break;
case V_24 :
if ( ! F_27 ( V_29 , & V_5 -> V_25 ) )
goto V_61;
V_42 = V_72 ;
break;
default:
F_8 ( V_63 L_5 , V_5 -> V_14 ) ;
V_5 -> V_12 = V_13 ;
}
goto V_61;
}
void
F_28 ( struct V_28 * V_29 , int V_73 , T_2 * V_74 )
{
struct V_4 * V_5 ;
struct V_75 * V_76 = & V_29 -> V_69 . V_70 [ 0 ] , * V_77 ;
int V_78 ;
if ( ! ( V_5 = V_29 -> V_43 ) || V_19 )
return;
V_78 = V_76 -> V_79 - ( ( char * ) V_74 - ( char * ) V_76 -> V_26 ) ;
V_78 >>= 2 ;
if ( ! V_74 || V_78 > ( 256 >> 2 ) ) {
V_5 -> V_12 = V_13 ;
return;
}
switch ( V_73 ) {
case V_68 :
if ( V_78 != 1 )
F_8 ( L_6 , V_78 ) ;
V_5 -> V_71 = * V_74 ;
break;
case V_24 :
V_77 = & V_5 -> V_25 ;
V_77 -> V_26 = F_4 ( V_78 << 2 , V_9 ) ;
if ( ! V_77 -> V_26 ) {
F_20 ( & V_47 ) ;
V_5 -> V_12 = V_13 ;
F_25 ( & V_47 ) ;
return;
}
V_77 -> V_79 = V_78 << 2 ;
memcpy ( V_77 -> V_26 , V_74 , V_78 << 2 ) ;
break;
}
F_20 ( & V_47 ) ;
F_14 ( V_5 ) ;
V_5 -> V_67 = V_29 -> V_66 ;
V_5 -> V_14 = V_73 ;
V_5 -> V_12 = V_23 ;
V_5 -> V_52 = V_51 ;
F_25 ( & V_47 ) ;
return;
}
static int
F_27 ( struct V_28 * V_29 , struct V_75 * V_80 )
{
struct V_75 * V_81 = & V_29 -> V_69 . V_70 [ 0 ] ;
if ( V_81 -> V_79 + V_80 -> V_79 > V_82 ) {
F_8 ( V_63 L_7 ,
V_80 -> V_79 ) ;
return 0 ;
}
memcpy ( ( char * ) V_81 -> V_26 + V_81 -> V_79 , V_80 -> V_26 , V_80 -> V_79 ) ;
V_81 -> V_79 += V_80 -> V_79 ;
return 1 ;
}
