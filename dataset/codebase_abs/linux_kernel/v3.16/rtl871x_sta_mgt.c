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
F_9 ( & V_2 -> V_5 ,
F_10 ( & V_12 -> V_20 ) ) ;
V_2 ++ ;
}
F_3 ( & V_12 -> V_9 ) ;
F_3 ( & V_12 -> V_10 ) ;
return V_26 ;
}
static void F_11 ( struct V_11 * V_12 )
{
unsigned long V_27 ;
struct V_28 * V_29 , * V_30 ;
struct V_1 * V_2 = NULL ;
F_12 ( & V_12 -> V_21 , V_27 ) ;
V_30 = F_10 ( & V_12 -> V_20 ) ;
V_29 = F_13 ( V_30 ) ;
while ( ( F_14 ( V_30 , V_29 ) ) == false ) {
V_2 = F_15 ( V_29 , struct V_1 , V_5 ) ;
V_29 = F_13 ( V_29 ) ;
}
F_16 ( & V_12 -> V_21 , V_27 ) ;
}
static void F_17 ( struct V_11 * V_12 )
{
F_11 ( V_12 ) ;
}
T_1 F_18 ( struct V_11 * V_12 )
{
if ( V_12 ) {
F_17 ( V_12 ) ;
F_19 ( V_12 -> V_14 ) ;
}
return V_26 ;
}
struct V_1 * F_20 ( struct V_11 * V_12 , V_3 * V_31 )
{
T_3 V_32 ;
T_2 V_33 ;
struct V_28 * V_34 ;
struct V_1 * V_2 ;
struct V_35 * V_36 ;
struct V_37 * V_38 ;
int V_13 = 0 ;
T_4 V_39 = 0xffff ;
unsigned long V_40 ;
V_36 = & V_12 -> V_20 ;
F_12 ( & ( V_36 -> V_4 ) , V_40 ) ;
if ( F_21 ( V_36 ) == true )
V_2 = NULL ;
else {
V_2 = F_15 ( F_13 ( & V_36 -> V_41 ) ,
struct V_1 , V_5 ) ;
F_22 ( & ( V_2 -> V_5 ) ) ;
V_32 = V_2 -> V_42 ;
F_1 ( V_2 ) ;
memcpy ( V_2 -> V_31 , V_31 , V_43 ) ;
V_33 = F_23 ( V_31 ) ;
if ( V_33 >= V_15 ) {
V_2 = NULL ;
goto exit;
}
V_34 = & ( V_12 -> V_25 [ V_33 ] ) ;
F_9 ( & V_2 -> V_6 , V_34 ) ;
V_12 -> V_22 ++ ;
for ( V_13 = 0 ; V_13 < 16 ; V_13 ++ )
memcpy ( & V_2 -> V_8 . V_44 . V_45 [ V_13 ] ,
& V_39 , 2 ) ;
for ( V_13 = 0 ; V_13 < 16 ; V_13 ++ ) {
V_38 = & V_2 -> V_46 [ V_13 ] ;
V_38 -> V_47 = V_12 -> V_47 ;
V_38 -> V_48 = 0xffff ;
V_38 -> V_49 = 0xffff ;
V_38 -> V_50 = 64 ;
F_8 ( & V_38 -> V_51 ) ;
F_24 ( V_38 ) ;
}
}
exit:
F_16 ( & ( V_36 -> V_4 ) , V_40 ) ;
return V_2 ;
}
void F_25 ( struct V_52 * V_47 , struct V_1 * V_2 )
{
int V_13 ;
unsigned long V_53 ;
struct V_35 * V_36 ;
struct V_37 * V_38 ;
struct V_54 * V_55 ;
struct V_56 * V_57 = & V_47 -> V_58 ;
struct V_11 * V_12 = & V_47 -> V_59 ;
if ( V_2 == NULL )
return;
V_36 = & V_12 -> V_20 ;
V_55 = & V_2 -> V_7 ;
F_12 ( & ( V_57 -> V_60 . V_4 ) , V_53 ) ;
F_26 ( V_57 , & V_55 -> V_61 . V_62 ) ;
F_22 ( & ( V_55 -> V_61 . V_63 ) ) ;
F_16 ( & ( V_57 -> V_60 . V_4 ) , V_53 ) ;
F_12 ( & ( V_57 -> V_64 . V_4 ) , V_53 ) ;
F_26 ( V_57 , & V_55 -> V_65 . V_62 ) ;
F_22 ( & ( V_55 -> V_65 . V_63 ) ) ;
F_16 ( & ( V_57 -> V_64 . V_4 ) , V_53 ) ;
F_12 ( & ( V_57 -> V_66 . V_4 ) , V_53 ) ;
F_26 ( V_57 , & V_55 -> V_67 . V_62 ) ;
F_22 ( & ( V_55 -> V_67 . V_63 ) ) ;
F_16 ( & ( V_57 -> V_66 . V_4 ) , V_53 ) ;
F_12 ( & ( V_57 -> V_68 . V_4 ) , V_53 ) ;
F_26 ( V_57 , & V_55 -> V_69 . V_62 ) ;
F_22 ( & ( V_55 -> V_69 . V_63 ) ) ;
F_16 ( & ( V_57 -> V_68 . V_4 ) , V_53 ) ;
F_22 ( & V_2 -> V_6 ) ;
V_12 -> V_22 -- ;
F_4 ( & V_2 -> V_7 ) ;
F_5 ( & V_2 -> V_8 ) ;
for ( V_13 = 0 ; V_13 < 16 ; V_13 ++ ) {
V_38 = & V_2 -> V_46 [ V_13 ] ;
F_27 ( & V_38 -> V_70 ) ;
}
F_28 ( & ( V_36 -> V_4 ) ) ;
F_9 ( & V_2 -> V_5 , F_10 ( V_36 ) ) ;
F_29 ( & ( V_36 -> V_4 ) ) ;
}
void F_30 ( struct V_52 * V_47 )
{
unsigned long V_27 ;
struct V_28 * V_29 , * V_30 ;
T_2 V_33 ;
struct V_1 * V_2 = NULL ;
struct V_11 * V_12 = & V_47 -> V_59 ;
struct V_1 * V_71 = F_31 ( V_47 ) ;
if ( V_12 -> V_22 == 1 )
return;
F_12 ( & V_12 -> V_21 , V_27 ) ;
for ( V_33 = 0 ; V_33 < V_15 ; V_33 ++ ) {
V_30 = & ( V_12 -> V_25 [ V_33 ] ) ;
V_29 = F_13 ( V_30 ) ;
while ( ( F_14 ( V_30 , V_29 ) ) == false ) {
V_2 = F_15 ( V_29 ,
struct V_1 , V_6 ) ;
V_29 = F_13 ( V_29 ) ;
if ( V_71 != V_2 )
F_25 ( V_47 , V_2 ) ;
}
}
F_16 ( & V_12 -> V_21 , V_27 ) ;
}
struct V_1 * F_32 ( struct V_11 * V_12 , V_3 * V_31 )
{
unsigned long V_27 ;
struct V_28 * V_29 , * V_30 ;
struct V_1 * V_2 = NULL ;
T_1 V_33 ;
if ( V_31 == NULL )
return NULL ;
V_33 = F_23 ( V_31 ) ;
F_12 ( & V_12 -> V_21 , V_27 ) ;
V_30 = & ( V_12 -> V_25 [ V_33 ] ) ;
V_29 = F_13 ( V_30 ) ;
while ( ( F_14 ( V_30 , V_29 ) ) == false ) {
V_2 = F_15 ( V_29 , struct V_1 , V_6 ) ;
if ( ( ! memcmp ( V_2 -> V_31 , V_31 , V_43 ) ) ) {
break;
}
V_2 = NULL ;
V_29 = F_13 ( V_29 ) ;
}
F_16 ( & V_12 -> V_21 , V_27 ) ;
return V_2 ;
}
void F_33 ( struct V_52 * V_47 )
{
struct V_1 * V_2 ;
struct V_72 * V_73 ;
unsigned char V_74 [ 6 ] = { 0xff , 0xff , 0xff , 0xff , 0xff , 0xff } ;
struct V_11 * V_12 = & V_47 -> V_59 ;
V_2 = F_20 ( V_12 , V_74 ) ;
if ( V_2 == NULL )
return;
V_73 = & ( V_2 -> V_7 . V_69 ) ;
}
struct V_1 * F_31 ( struct V_52 * V_47 )
{
struct V_1 * V_2 ;
struct V_11 * V_12 = & V_47 -> V_59 ;
V_3 V_75 [ V_43 ] = { 0xff , 0xff , 0xff , 0xff , 0xff , 0xff } ;
V_2 = F_32 ( V_12 , V_75 ) ;
return V_2 ;
}
V_3 F_34 ( struct V_76 * V_77 , V_3 * V_78 )
{
return true ;
}
