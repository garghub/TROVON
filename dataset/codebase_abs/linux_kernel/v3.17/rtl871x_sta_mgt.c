static void F_1 ( struct V_1 * V_2 )
{
memset ( ( V_3 * ) V_2 , 0 , sizeof( struct V_1 ) ) ;
F_2 ( & V_2 -> V_4 ) ;
F_3 ( & V_2 -> V_5 ) ;
F_3 ( & V_2 -> V_6 ) ;
F_4 ( & V_2 -> V_7 ) ;
F_5 ( & V_2 -> V_8 ) ;
F_3 ( & V_2 -> V_9 ) ;
F_3 ( & V_2 -> V_10 ) ;
}
T_1 F_6 ( struct V_11 * V_12 )
{
struct V_1 * V_2 ;
T_2 V_13 ;
V_12 -> V_14 = F_7 ( sizeof( struct V_1 ) *
V_15 + 4 , V_16 ) ;
if ( V_12 -> V_14 == NULL )
return V_17 ;
V_12 -> V_18 = V_12 -> V_14 + 4 -
( ( V_19 ) ( V_12 -> V_14 ) & 3 ) ;
F_8 ( & V_12 -> V_20 ) ;
F_2 ( & V_12 -> V_21 ) ;
V_12 -> V_22 = 0 ;
F_8 ( & V_12 -> V_23 ) ;
F_8 ( & V_12 -> V_24 ) ;
V_2 = (struct V_1 * ) ( V_12 -> V_18 ) ;
for ( V_13 = 0 ; V_13 < V_15 ; V_13 ++ ) {
F_1 ( V_2 ) ;
F_3 ( & ( V_12 -> V_25 [ V_13 ] ) ) ;
F_9 ( & V_2 -> V_5 , & V_12 -> V_20 . V_26 ) ;
V_2 ++ ;
}
F_3 ( & V_12 -> V_9 ) ;
F_3 ( & V_12 -> V_10 ) ;
return V_27 ;
}
static void F_10 ( struct V_11 * V_12 )
{
unsigned long V_28 ;
struct V_29 * V_30 , * V_31 ;
struct V_1 * V_2 = NULL ;
F_11 ( & V_12 -> V_21 , V_28 ) ;
V_31 = & V_12 -> V_20 . V_26 ;
V_30 = V_31 -> V_32 ;
while ( ( F_12 ( V_31 , V_30 ) ) == false ) {
V_2 = F_13 ( V_30 , struct V_1 , V_5 ) ;
V_30 = V_30 -> V_32 ;
}
F_14 ( & V_12 -> V_21 , V_28 ) ;
}
static void F_15 ( struct V_11 * V_12 )
{
F_10 ( V_12 ) ;
}
T_1 F_16 ( struct V_11 * V_12 )
{
if ( V_12 ) {
F_15 ( V_12 ) ;
F_17 ( V_12 -> V_14 ) ;
}
return V_27 ;
}
struct V_1 * F_18 ( struct V_11 * V_12 , V_3 * V_33 )
{
T_3 V_34 ;
T_2 V_35 ;
struct V_29 * V_36 ;
struct V_1 * V_2 ;
struct V_37 * V_38 ;
struct V_39 * V_40 ;
int V_13 = 0 ;
T_4 V_41 = 0xffff ;
unsigned long V_42 ;
V_38 = & V_12 -> V_20 ;
F_11 ( & ( V_38 -> V_4 ) , V_42 ) ;
if ( F_19 ( & V_38 -> V_26 ) )
V_2 = NULL ;
else {
V_2 = F_13 ( V_38 -> V_26 . V_32 ,
struct V_1 , V_5 ) ;
F_20 ( & ( V_2 -> V_5 ) ) ;
V_34 = V_2 -> V_43 ;
F_1 ( V_2 ) ;
memcpy ( V_2 -> V_33 , V_33 , V_44 ) ;
V_35 = F_21 ( V_33 ) ;
if ( V_35 >= V_15 ) {
V_2 = NULL ;
goto exit;
}
V_36 = & ( V_12 -> V_25 [ V_35 ] ) ;
F_9 ( & V_2 -> V_6 , V_36 ) ;
V_12 -> V_22 ++ ;
for ( V_13 = 0 ; V_13 < 16 ; V_13 ++ )
memcpy ( & V_2 -> V_8 . V_45 . V_46 [ V_13 ] ,
& V_41 , 2 ) ;
for ( V_13 = 0 ; V_13 < 16 ; V_13 ++ ) {
V_40 = & V_2 -> V_47 [ V_13 ] ;
V_40 -> V_48 = V_12 -> V_48 ;
V_40 -> V_49 = 0xffff ;
V_40 -> V_50 = 0xffff ;
V_40 -> V_51 = 64 ;
F_8 ( & V_40 -> V_52 ) ;
F_22 ( V_40 ) ;
}
}
exit:
F_14 ( & ( V_38 -> V_4 ) , V_42 ) ;
return V_2 ;
}
void F_23 ( struct V_53 * V_48 , struct V_1 * V_2 )
{
int V_13 ;
unsigned long V_54 ;
struct V_37 * V_38 ;
struct V_39 * V_40 ;
struct V_55 * V_56 ;
struct V_57 * V_58 = & V_48 -> V_59 ;
struct V_11 * V_12 = & V_48 -> V_60 ;
if ( V_2 == NULL )
return;
V_38 = & V_12 -> V_20 ;
V_56 = & V_2 -> V_7 ;
F_11 ( & ( V_58 -> V_61 . V_4 ) , V_54 ) ;
F_24 ( V_58 , & V_56 -> V_62 . V_63 ) ;
F_20 ( & ( V_56 -> V_62 . V_64 ) ) ;
F_14 ( & ( V_58 -> V_61 . V_4 ) , V_54 ) ;
F_11 ( & ( V_58 -> V_65 . V_4 ) , V_54 ) ;
F_24 ( V_58 , & V_56 -> V_66 . V_63 ) ;
F_20 ( & ( V_56 -> V_66 . V_64 ) ) ;
F_14 ( & ( V_58 -> V_65 . V_4 ) , V_54 ) ;
F_11 ( & ( V_58 -> V_67 . V_4 ) , V_54 ) ;
F_24 ( V_58 , & V_56 -> V_68 . V_63 ) ;
F_20 ( & ( V_56 -> V_68 . V_64 ) ) ;
F_14 ( & ( V_58 -> V_67 . V_4 ) , V_54 ) ;
F_11 ( & ( V_58 -> V_69 . V_4 ) , V_54 ) ;
F_24 ( V_58 , & V_56 -> V_70 . V_63 ) ;
F_20 ( & ( V_56 -> V_70 . V_64 ) ) ;
F_14 ( & ( V_58 -> V_69 . V_4 ) , V_54 ) ;
F_20 ( & V_2 -> V_6 ) ;
V_12 -> V_22 -- ;
F_4 ( & V_2 -> V_7 ) ;
F_5 ( & V_2 -> V_8 ) ;
for ( V_13 = 0 ; V_13 < 16 ; V_13 ++ ) {
V_40 = & V_2 -> V_47 [ V_13 ] ;
F_25 ( & V_40 -> V_71 ) ;
}
F_26 ( & ( V_38 -> V_4 ) ) ;
F_9 ( & V_2 -> V_5 , & V_38 -> V_26 ) ;
F_27 ( & ( V_38 -> V_4 ) ) ;
}
void F_28 ( struct V_53 * V_48 )
{
unsigned long V_28 ;
struct V_29 * V_30 , * V_31 ;
T_2 V_35 ;
struct V_1 * V_2 = NULL ;
struct V_11 * V_12 = & V_48 -> V_60 ;
struct V_1 * V_72 = F_29 ( V_48 ) ;
if ( V_12 -> V_22 == 1 )
return;
F_11 ( & V_12 -> V_21 , V_28 ) ;
for ( V_35 = 0 ; V_35 < V_15 ; V_35 ++ ) {
V_31 = & ( V_12 -> V_25 [ V_35 ] ) ;
V_30 = V_31 -> V_32 ;
while ( ( F_12 ( V_31 , V_30 ) ) == false ) {
V_2 = F_13 ( V_30 ,
struct V_1 , V_6 ) ;
V_30 = V_30 -> V_32 ;
if ( V_72 != V_2 )
F_23 ( V_48 , V_2 ) ;
}
}
F_14 ( & V_12 -> V_21 , V_28 ) ;
}
struct V_1 * F_30 ( struct V_11 * V_12 , V_3 * V_33 )
{
unsigned long V_28 ;
struct V_29 * V_30 , * V_31 ;
struct V_1 * V_2 = NULL ;
T_1 V_35 ;
if ( V_33 == NULL )
return NULL ;
V_35 = F_21 ( V_33 ) ;
F_11 ( & V_12 -> V_21 , V_28 ) ;
V_31 = & ( V_12 -> V_25 [ V_35 ] ) ;
V_30 = V_31 -> V_32 ;
while ( ( F_12 ( V_31 , V_30 ) ) == false ) {
V_2 = F_13 ( V_30 , struct V_1 , V_6 ) ;
if ( ( ! memcmp ( V_2 -> V_33 , V_33 , V_44 ) ) ) {
break;
}
V_2 = NULL ;
V_30 = V_30 -> V_32 ;
}
F_14 ( & V_12 -> V_21 , V_28 ) ;
return V_2 ;
}
void F_31 ( struct V_53 * V_48 )
{
struct V_1 * V_2 ;
struct V_73 * V_74 ;
unsigned char V_75 [ 6 ] = { 0xff , 0xff , 0xff , 0xff , 0xff , 0xff } ;
struct V_11 * V_12 = & V_48 -> V_60 ;
V_2 = F_18 ( V_12 , V_75 ) ;
if ( V_2 == NULL )
return;
V_74 = & ( V_2 -> V_7 . V_70 ) ;
}
struct V_1 * F_29 ( struct V_53 * V_48 )
{
struct V_1 * V_2 ;
struct V_11 * V_12 = & V_48 -> V_60 ;
V_3 V_76 [ V_44 ] = { 0xff , 0xff , 0xff , 0xff , 0xff , 0xff } ;
V_2 = F_30 ( V_12 , V_76 ) ;
return V_2 ;
}
V_3 F_32 ( struct V_77 * V_78 , V_3 * V_79 )
{
return true ;
}
