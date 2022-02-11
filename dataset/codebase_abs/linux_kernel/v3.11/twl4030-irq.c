static T_1 F_1 ( int V_1 , void * V_2 )
{
T_1 V_3 ;
T_2 V_4 ;
V_3 = F_2 ( V_5 , & V_4 ,
V_6 ) ;
if ( V_3 ) {
F_3 ( L_1 , V_3 ) ;
return V_7 ;
}
while ( V_4 ) {
unsigned long V_8 = F_4 ( V_4 ) ;
unsigned int V_1 ;
V_4 &= ~ F_5 ( V_8 ) ;
V_1 = V_8 + V_9 ;
F_6 ( V_1 ) ;
}
return V_10 ;
}
static int F_7 ( unsigned line )
{
const struct V_11 * V_11 ;
T_2 V_12 [ 4 ] ;
int V_13 ;
int V_14 ;
if ( line > 1 )
return - V_15 ;
V_16 = line ;
memset ( V_12 , 0xff , sizeof V_12 ) ;
V_11 = V_17 ;
for ( V_13 = 0 ; V_13 < V_18 ; V_13 ++ , V_11 ++ ) {
if ( ! V_11 -> V_19 )
continue;
if ( V_11 -> V_20 <= line )
continue;
V_14 = F_8 ( V_11 -> V_21 , V_12 ,
V_11 -> V_22 [ line ] . V_23 , V_11 -> V_19 ) ;
if ( V_14 < 0 )
F_9 ( L_2 ,
V_14 , V_11 -> V_24 , L_3 ) ;
if ( V_11 -> V_25 ) {
V_14 = F_10 ( V_11 -> V_21 ,
V_26 ,
V_11 -> V_27 ) ;
if ( V_14 < 0 )
F_9 ( L_2 ,
V_14 , V_11 -> V_24 , L_4 ) ;
}
}
V_11 = V_17 ;
for ( V_13 = 0 ; V_13 < V_18 ; V_13 ++ , V_11 ++ ) {
T_2 V_28 [ 4 ] ;
int V_29 ;
if ( ! V_11 -> V_19 )
continue;
if ( V_11 -> V_20 <= line )
continue;
for ( V_29 = 0 ; V_29 < 2 ; V_29 ++ ) {
V_14 = F_11 ( V_11 -> V_21 , V_28 ,
V_11 -> V_22 [ line ] . V_30 , V_11 -> V_19 ) ;
if ( V_14 < 0 )
F_9 ( L_2 ,
V_14 , V_11 -> V_24 , L_5 ) ;
if ( ! V_11 -> V_25 )
V_14 = F_8 ( V_11 -> V_21 , V_12 ,
V_11 -> V_22 [ line ] . V_30 ,
V_11 -> V_19 ) ;
}
}
return 0 ;
}
static inline void F_12 ( int V_1 )
{
#ifdef F_13
F_14 ( V_1 , V_31 ) ;
#else
F_15 ( V_1 ) ;
#endif
}
static void F_16 ( struct V_32 * V_33 )
{
struct V_34 * V_35 = F_17 ( V_33 ) ;
V_35 -> V_36 |= F_5 ( V_33 -> V_1 - V_35 -> V_37 ) ;
V_35 -> V_38 = true ;
}
static void F_18 ( struct V_32 * V_33 )
{
struct V_34 * V_35 = F_17 ( V_33 ) ;
V_35 -> V_36 &= ~ F_5 ( V_33 -> V_1 - V_35 -> V_37 ) ;
V_35 -> V_38 = true ;
}
static int F_19 ( struct V_32 * V_33 , unsigned V_39 )
{
struct V_34 * V_35 = F_17 ( V_33 ) ;
if ( V_39 & ~ ( V_40 | V_41 ) )
return - V_15 ;
if ( F_20 ( V_33 ) != V_39 )
V_35 -> V_42 |= F_5 ( V_33 -> V_1 - V_35 -> V_37 ) ;
return 0 ;
}
static void F_21 ( struct V_32 * V_33 )
{
struct V_34 * V_35 = F_17 ( V_33 ) ;
F_22 ( & V_35 -> V_43 ) ;
}
static void F_23 ( struct V_32 * V_33 )
{
struct V_34 * V_35 = F_17 ( V_33 ) ;
const struct V_11 * V_11 = V_35 -> V_11 ;
int V_14 ;
if ( V_35 -> V_38 ) {
union {
T_3 V_44 ;
T_2 V_45 [ 4 ] ;
} V_36 ;
V_36 . V_44 = F_24 ( V_35 -> V_36 ) ;
V_35 -> V_38 = false ;
V_14 = F_8 ( V_11 -> V_21 , V_36 . V_45 ,
V_11 -> V_22 [ V_16 ] . V_23 ,
V_11 -> V_19 ) ;
if ( V_14 )
F_9 ( L_6 , V_46 ,
L_7 , V_14 ) ;
}
if ( V_35 -> V_42 ) {
T_3 V_42 ;
T_2 V_45 [ 6 ] ;
V_42 = V_35 -> V_42 ;
V_35 -> V_42 = 0 ;
V_14 = F_11 ( V_11 -> V_21 , V_45 ,
V_11 -> V_47 , V_11 -> V_48 ) ;
if ( V_14 ) {
F_9 ( L_6 , V_46 ,
L_8 , V_14 ) ;
return;
}
while ( V_42 ) {
int V_13 = F_25 ( V_42 ) - 1 ;
int V_49 = V_13 >> 2 ;
int V_50 = ( V_13 & 0x3 ) * 2 ;
unsigned int type ;
V_45 [ V_49 ] &= ~ ( 0x03 << V_50 ) ;
type = F_26 ( V_13 + V_35 -> V_37 ) ;
if ( type & V_41 )
V_45 [ V_49 ] |= F_5 ( V_50 + 1 ) ;
if ( type & V_40 )
V_45 [ V_49 ] |= F_5 ( V_50 + 0 ) ;
V_42 &= ~ F_5 ( V_13 ) ;
}
V_14 = F_8 ( V_11 -> V_21 , V_45 ,
V_11 -> V_47 , V_11 -> V_48 ) ;
if ( V_14 )
F_9 ( L_6 , V_46 ,
L_7 , V_14 ) ;
}
F_27 ( & V_35 -> V_43 ) ;
}
static inline int F_28 ( const struct V_11 * V_11 )
{
int V_14 ;
union {
T_2 V_45 [ 4 ] ;
T_3 V_44 ;
} V_51 ;
V_51 . V_44 = 0 ;
V_14 = F_11 ( V_11 -> V_21 , V_51 . V_45 ,
V_11 -> V_22 [ V_16 ] . V_30 , V_11 -> V_19 ) ;
return ( V_14 < 0 ) ? V_14 : F_29 ( V_51 . V_44 ) ;
}
static T_1 F_30 ( int V_1 , void * V_33 )
{
struct V_34 * V_35 = F_31 ( V_1 ) ;
const struct V_11 * V_11 = V_35 -> V_11 ;
int V_51 ;
V_51 = F_28 ( V_11 ) ;
if ( V_51 < 0 ) {
F_9 ( L_9 ,
V_11 -> V_24 , V_51 ) ;
return V_10 ;
}
while ( V_51 ) {
V_1 = F_25 ( V_51 ) ;
V_1 -- ;
V_51 &= ~ F_5 ( V_1 ) ;
if ( V_1 < V_11 -> V_52 )
F_6 ( V_35 -> V_37 + V_1 ) ;
else
F_9 ( L_10 ,
V_11 -> V_24 , V_1 ) ;
}
return V_10 ;
}
int F_32 ( struct V_53 * V_54 , int V_21 , int V_37 )
{
int V_55 ;
const struct V_11 * V_11 = NULL ;
struct V_34 * V_35 ;
int V_13 , V_1 ;
int V_14 = - V_15 ;
for ( V_55 = 0 , V_11 = V_17 ; V_55 < V_18 ;
V_55 ++ , V_11 ++ ) {
if ( V_11 -> V_21 == V_21 && V_11 -> V_25 ) {
V_14 = 0 ;
break;
}
}
if ( V_14 < 0 )
return V_14 ;
V_35 = F_33 ( sizeof *V_35 , V_56 ) ;
if ( ! V_35 )
return - V_57 ;
V_35 -> V_37 = V_37 ;
V_35 -> V_11 = V_11 ;
V_35 -> V_36 = ~ 0 ;
F_34 ( & V_35 -> V_43 ) ;
for ( V_13 = 0 ; V_13 < V_11 -> V_52 ; V_13 ++ ) {
V_1 = V_37 + V_13 ;
F_35 ( V_1 , V_35 ) ;
F_36 ( V_1 , & V_58 ,
V_59 ) ;
F_37 ( V_1 , 1 ) ;
F_12 ( V_1 ) ;
}
V_1 = V_55 + V_9 ;
F_38 ( V_1 , V_35 ) ;
V_35 -> V_60 = F_39 ( V_56 , L_11 , V_11 -> V_24 ) ;
V_14 = F_40 ( V_1 , NULL , F_30 ,
V_61 ,
V_35 -> V_60 ? : V_11 -> V_24 , NULL ) ;
F_41 ( V_54 , L_12 , V_11 -> V_24 ,
V_1 , V_37 , V_37 + V_13 - 1 ) ;
return V_14 < 0 ? V_14 : V_37 ;
}
int F_42 ( struct V_53 * V_54 , int V_62 )
{
static struct V_63 V_64 ;
int V_14 , V_13 ;
int V_37 , V_65 , V_66 ;
struct V_67 * V_68 = V_54 -> V_69 ;
V_66 = V_70 + V_71 ;
V_37 = F_43 ( - 1 , 0 , V_66 , 0 ) ;
if ( F_44 ( V_37 ) ) {
F_45 ( V_54 , L_13 ) ;
return V_37 ;
}
F_46 ( V_68 , V_66 , V_37 , 0 ,
& V_72 , NULL ) ;
V_65 = V_37 + V_71 ;
V_14 = F_7 ( V_73 ) ;
if ( V_14 < 0 )
return V_14 ;
V_9 = V_37 ;
V_64 = V_74 ;
V_64 . V_24 = L_14 ;
V_58 . V_75 = V_74 . V_75 ;
for ( V_13 = V_37 ; V_13 < V_65 ; V_13 ++ ) {
F_36 ( V_13 , & V_64 ,
V_76 ) ;
F_37 ( V_13 , 1 ) ;
F_12 ( V_13 ) ;
}
F_41 ( V_54 , L_12 , L_15 ,
V_62 , V_37 , V_65 ) ;
V_14 = F_32 ( V_54 , V_77 , V_65 ) ;
if ( V_14 < 0 ) {
F_45 ( V_54 , L_16 , V_14 ) ;
goto V_78;
}
V_14 = F_40 ( V_62 , NULL , F_1 ,
V_79 ,
L_17 , NULL ) ;
if ( V_14 < 0 ) {
F_45 ( V_54 , L_18 , V_62 , V_14 ) ;
goto V_80;
}
F_47 ( V_62 ) ;
return V_37 ;
V_80:
V_78:
for ( V_13 = V_37 ; V_13 < V_65 ; V_13 ++ ) {
F_37 ( V_13 , 0 ) ;
F_36 ( V_13 , NULL , NULL ) ;
}
return V_14 ;
}
int F_48 ( void )
{
if ( V_9 ) {
F_9 ( L_19 ) ;
return - V_81 ;
}
return 0 ;
}
int F_49 ( const char * V_82 )
{
if ( ! strcmp ( V_82 , L_20 ) ) {
V_17 = V_83 ;
V_18 = F_50 ( V_83 ) ;
} else {
V_17 = V_84 ;
V_18 = F_50 ( V_84 ) ;
}
return 0 ;
}
