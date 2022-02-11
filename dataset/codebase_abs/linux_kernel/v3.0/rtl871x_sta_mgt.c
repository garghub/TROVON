static void F_1 ( struct V_1 * V_2 )
{
memset ( ( V_3 * ) V_2 , 0 , sizeof( struct V_1 ) ) ;
F_2 ( & V_2 -> V_4 ) ;
F_3 ( & V_2 -> V_5 ) ;
F_3 ( & V_2 -> V_6 ) ;
F_4 ( & V_2 -> V_7 ) ;
F_5 ( & V_2 -> V_8 ) ;
#ifdef F_6
F_3 ( & V_2 -> V_9 ) ;
#endif
}
T_1 F_7 ( struct V_10 * V_11 )
{
struct V_1 * V_2 ;
T_2 V_12 ;
V_11 -> V_13 = F_8 ( sizeof( struct V_1 ) *
V_14 + 4 ) ;
if ( V_11 -> V_13 == NULL )
return V_15 ;
V_11 -> V_16 = V_11 -> V_13 + 4 -
( ( V_17 ) ( V_11 -> V_13 ) & 3 ) ;
F_9 ( & V_11 -> V_18 ) ;
F_2 ( & V_11 -> V_19 ) ;
V_11 -> V_20 = 0 ;
F_9 ( & V_11 -> V_21 ) ;
F_9 ( & V_11 -> V_22 ) ;
V_2 = (struct V_1 * ) ( V_11 -> V_16 ) ;
for ( V_12 = 0 ; V_12 < V_14 ; V_12 ++ ) {
F_1 ( V_2 ) ;
F_3 ( & ( V_11 -> V_23 [ V_12 ] ) ) ;
F_10 ( & V_2 -> V_5 ,
F_11 ( & V_11 -> V_18 ) ) ;
V_2 ++ ;
}
#ifdef F_6
F_3 ( & V_11 -> V_24 ) ;
F_3 ( & V_11 -> V_9 ) ;
#endif
return V_25 ;
}
static void F_12 ( struct V_10 * V_11 )
{
unsigned long V_26 ;
struct V_27 * V_28 , * V_29 ;
struct V_1 * V_2 = NULL ;
F_13 ( & V_11 -> V_19 , V_26 ) ;
V_29 = F_11 ( & V_11 -> V_18 ) ;
V_28 = F_14 ( V_29 ) ;
while ( ( F_15 ( V_29 , V_28 ) ) == false ) {
V_2 = F_16 ( V_28 , struct V_1 , V_5 ) ;
V_28 = F_14 ( V_28 ) ;
}
F_17 ( & V_11 -> V_19 , V_26 ) ;
}
static void F_18 ( struct V_10 * V_11 )
{
F_12 ( V_11 ) ;
}
T_1 F_19 ( struct V_10 * V_11 )
{
if ( V_11 ) {
F_18 ( V_11 ) ;
F_20 ( V_11 -> V_13 ) ;
}
return V_25 ;
}
struct V_1 * F_21 ( struct V_10 * V_11 , V_3 * V_30 )
{
T_3 V_31 ;
T_2 V_32 ;
struct V_27 * V_33 ;
struct V_1 * V_2 ;
struct V_34 * V_35 ;
struct V_36 * V_37 ;
int V_12 = 0 ;
T_4 V_38 = 0xffff ;
unsigned long V_39 ;
V_35 = & V_11 -> V_18 ;
F_13 ( & ( V_35 -> V_4 ) , V_39 ) ;
if ( F_22 ( V_35 ) == true )
V_2 = NULL ;
else {
V_2 = F_16 ( F_14 ( & V_35 -> V_40 ) ,
struct V_1 , V_5 ) ;
F_23 ( & ( V_2 -> V_5 ) ) ;
V_31 = V_2 -> V_41 ;
F_1 ( V_2 ) ;
memcpy ( V_2 -> V_30 , V_30 , V_42 ) ;
V_32 = F_24 ( V_30 ) ;
if ( V_32 >= V_14 ) {
V_2 = NULL ;
goto exit;
}
V_33 = & ( V_11 -> V_23 [ V_32 ] ) ;
F_10 ( & V_2 -> V_6 , V_33 ) ;
V_11 -> V_20 ++ ;
for ( V_12 = 0 ; V_12 < 16 ; V_12 ++ )
memcpy ( & V_2 -> V_8 . V_43 . V_44 [ V_12 ] ,
& V_38 , 2 ) ;
for ( V_12 = 0 ; V_12 < 16 ; V_12 ++ ) {
V_37 = & V_2 -> V_45 [ V_12 ] ;
V_37 -> V_46 = V_11 -> V_46 ;
V_37 -> V_47 = 0xffff ;
V_37 -> V_48 = 0xffff ;
V_37 -> V_49 = 64 ;
F_9 ( & V_37 -> V_50 ) ;
F_25 ( V_37 ) ;
}
}
exit:
F_17 ( & ( V_35 -> V_4 ) , V_39 ) ;
return V_2 ;
}
void F_26 ( struct V_51 * V_46 , struct V_1 * V_2 )
{
int V_12 ;
unsigned long V_52 ;
struct V_34 * V_35 ;
struct V_36 * V_37 ;
struct V_53 * V_54 ;
struct V_55 * V_56 = & V_46 -> V_57 ;
struct V_10 * V_11 = & V_46 -> V_58 ;
if ( V_2 == NULL )
return;
V_35 = & V_11 -> V_18 ;
V_54 = & V_2 -> V_7 ;
F_13 ( & ( V_56 -> V_59 . V_4 ) , V_52 ) ;
F_27 ( V_56 , & V_54 -> V_60 . V_61 ) ;
F_23 ( & ( V_54 -> V_60 . V_62 ) ) ;
F_17 ( & ( V_56 -> V_59 . V_4 ) , V_52 ) ;
F_13 ( & ( V_56 -> V_63 . V_4 ) , V_52 ) ;
F_27 ( V_56 , & V_54 -> V_64 . V_61 ) ;
F_23 ( & ( V_54 -> V_64 . V_62 ) ) ;
F_17 ( & ( V_56 -> V_63 . V_4 ) , V_52 ) ;
F_13 ( & ( V_56 -> V_65 . V_4 ) , V_52 ) ;
F_27 ( V_56 , & V_54 -> V_66 . V_61 ) ;
F_23 ( & ( V_54 -> V_66 . V_62 ) ) ;
F_17 ( & ( V_56 -> V_65 . V_4 ) , V_52 ) ;
F_13 ( & ( V_56 -> V_67 . V_4 ) , V_52 ) ;
F_27 ( V_56 , & V_54 -> V_68 . V_61 ) ;
F_23 ( & ( V_54 -> V_68 . V_62 ) ) ;
F_17 ( & ( V_56 -> V_67 . V_4 ) , V_52 ) ;
F_23 ( & V_2 -> V_6 ) ;
V_11 -> V_20 -- ;
F_4 ( & V_2 -> V_7 ) ;
F_5 ( & V_2 -> V_8 ) ;
for ( V_12 = 0 ; V_12 < 16 ; V_12 ++ ) {
V_37 = & V_2 -> V_45 [ V_12 ] ;
F_28 ( & V_37 -> V_69 ) ;
}
F_29 ( & ( V_35 -> V_4 ) ) ;
F_10 ( & V_2 -> V_5 , F_11 ( V_35 ) ) ;
F_30 ( & ( V_35 -> V_4 ) ) ;
}
void F_31 ( struct V_51 * V_46 )
{
unsigned long V_26 ;
struct V_27 * V_28 , * V_29 ;
T_2 V_32 ;
struct V_1 * V_2 = NULL ;
struct V_10 * V_11 = & V_46 -> V_58 ;
struct V_1 * V_70 = F_32 ( V_46 ) ;
if ( V_11 -> V_20 == 1 )
return;
F_13 ( & V_11 -> V_19 , V_26 ) ;
for ( V_32 = 0 ; V_32 < V_14 ; V_32 ++ ) {
V_29 = & ( V_11 -> V_23 [ V_32 ] ) ;
V_28 = F_14 ( V_29 ) ;
while ( ( F_15 ( V_29 , V_28 ) ) == false ) {
V_2 = F_16 ( V_28 ,
struct V_1 , V_6 ) ;
V_28 = F_14 ( V_28 ) ;
if ( V_70 != V_2 )
F_26 ( V_46 , V_2 ) ;
}
}
F_17 ( & V_11 -> V_19 , V_26 ) ;
}
struct V_1 * F_33 ( struct V_10 * V_11 , V_3 * V_30 )
{
unsigned long V_26 ;
struct V_27 * V_28 , * V_29 ;
struct V_1 * V_2 = NULL ;
T_1 V_32 ;
if ( V_30 == NULL )
return NULL ;
V_32 = F_24 ( V_30 ) ;
F_13 ( & V_11 -> V_19 , V_26 ) ;
V_29 = & ( V_11 -> V_23 [ V_32 ] ) ;
V_28 = F_14 ( V_29 ) ;
while ( ( F_15 ( V_29 , V_28 ) ) == false ) {
V_2 = F_16 ( V_28 , struct V_1 , V_6 ) ;
if ( ( ! memcmp ( V_2 -> V_30 , V_30 , V_42 ) ) ) {
break;
}
V_2 = NULL ;
V_28 = F_14 ( V_28 ) ;
}
F_17 ( & V_11 -> V_19 , V_26 ) ;
return V_2 ;
}
void F_34 ( struct V_51 * V_46 )
{
struct V_1 * V_2 ;
struct V_71 * V_72 ;
unsigned char V_73 [ 6 ] = { 0xff , 0xff , 0xff , 0xff , 0xff , 0xff } ;
struct V_10 * V_11 = & V_46 -> V_58 ;
V_2 = F_21 ( V_11 , V_73 ) ;
if ( V_2 == NULL )
return;
V_72 = & ( V_2 -> V_7 . V_68 ) ;
}
struct V_1 * F_32 ( struct V_51 * V_46 )
{
struct V_1 * V_2 ;
struct V_10 * V_11 = & V_46 -> V_58 ;
V_3 V_74 [ V_42 ] = { 0xff , 0xff , 0xff , 0xff , 0xff , 0xff } ;
V_2 = F_33 ( V_11 , V_74 ) ;
return V_2 ;
}
V_3 F_35 ( struct V_75 * V_76 , V_3 * V_77 )
{
return true ;
}
