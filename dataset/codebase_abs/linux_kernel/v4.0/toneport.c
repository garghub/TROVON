static int F_1 ( struct V_1 * V_2 , int V_3 , int V_4 )
{
int V_5 ;
V_5 = F_2 ( V_2 , F_3 ( V_2 , 0 ) , 0x67 ,
V_6 | V_7 | V_8 ,
V_3 , V_4 , NULL , 0 , V_9 * V_10 ) ;
if ( V_5 < 0 ) {
F_4 ( & V_2 -> V_11 , L_1 , V_5 ) ;
return V_5 ;
}
return 0 ;
}
static int F_5 ( struct V_12 * V_13 ,
struct V_14 * V_15 )
{
V_15 -> type = V_16 ;
V_15 -> V_17 = 1 ;
V_15 -> V_18 . integer . V_19 = 0 ;
V_15 -> V_18 . integer . V_20 = 256 ;
return 0 ;
}
static int F_6 ( struct V_12 * V_13 ,
struct V_21 * V_22 )
{
struct V_23 * V_24 = F_7 ( V_13 ) ;
V_22 -> V_18 . integer . V_18 [ 0 ] = V_24 -> V_25 ;
return 0 ;
}
static int F_8 ( struct V_12 * V_13 ,
struct V_21 * V_22 )
{
struct V_23 * V_24 = F_7 ( V_13 ) ;
int V_26 ;
if ( V_22 -> V_18 . integer . V_18 [ 0 ] == V_24 -> V_25 )
return 0 ;
V_24 -> V_25 = V_22 -> V_18 . integer . V_18 [ 0 ] ;
if ( V_24 -> V_25 > 0 ) {
V_26 = F_9 ( V_24 , V_27 ) ;
if ( V_26 < 0 ) {
V_24 -> V_25 = 0 ;
F_10 ( V_24 , V_27 ) ;
return V_26 ;
}
} else {
F_10 ( V_24 , V_27 ) ;
}
return 1 ;
}
static int F_11 ( struct V_12 * V_13 ,
struct V_14 * V_15 )
{
const int V_28 = F_12 ( V_29 ) ;
V_15 -> type = V_30 ;
V_15 -> V_17 = 1 ;
V_15 -> V_18 . V_31 . V_32 = V_28 ;
if ( V_15 -> V_18 . V_31 . V_33 >= V_28 )
V_15 -> V_18 . V_31 . V_33 = V_28 - 1 ;
strcpy ( V_15 -> V_18 . V_31 . V_34 ,
V_29 [ V_15 -> V_18 . V_31 . V_33 ] . V_34 ) ;
return 0 ;
}
static int F_13 ( struct V_12 * V_13 ,
struct V_21 * V_22 )
{
struct V_23 * V_24 = F_7 ( V_13 ) ;
struct V_35 * V_36 =
(struct V_35 * ) V_24 -> V_37 ;
V_22 -> V_18 . V_31 . V_33 [ 0 ] = V_36 -> V_38 ;
return 0 ;
}
static int F_14 ( struct V_12 * V_13 ,
struct V_21 * V_22 )
{
struct V_23 * V_24 = F_7 ( V_13 ) ;
struct V_35 * V_36 =
(struct V_35 * ) V_24 -> V_37 ;
unsigned int V_38 ;
V_38 = V_22 -> V_18 . V_31 . V_33 [ 0 ] ;
if ( V_38 >= F_12 ( V_29 ) )
return - V_39 ;
if ( V_38 == V_36 -> V_38 )
return 0 ;
V_36 -> V_38 = V_38 ;
F_1 ( V_36 -> V_37 . V_2 ,
V_29 [ V_38 ] . V_40 , 0x0000 ) ;
return 1 ;
}
static void F_15 ( unsigned long V_41 )
{
struct V_35 * V_36 = (struct V_35 * ) V_41 ;
struct V_42 * V_37 = & V_36 -> V_37 ;
F_9 ( V_37 -> V_24 , V_27 ) ;
}
static bool F_16 ( struct V_35 * V_36 )
{
switch ( V_36 -> type ) {
case V_43 :
case V_44 :
return true ;
default:
return false ;
}
}
static void F_17 ( struct V_35 * V_36 )
{
F_1 ( V_36 -> V_37 . V_2 ,
( V_36 -> V_45 [ 0 ] . V_11 . V_46 << 8 ) | 0x0002 ,
V_36 -> V_45 [ 1 ] . V_11 . V_46 ) ;
}
static void F_18 ( struct V_47 * V_48 ,
enum V_49 V_46 )
{
struct V_50 * V_45 =
F_19 ( V_48 , struct V_50 , V_11 ) ;
F_17 ( V_45 -> V_36 ) ;
}
static int F_20 ( struct V_35 * V_36 )
{
struct V_51 * V_11 = & V_36 -> V_37 . V_2 -> V_11 ;
int V_52 , V_26 ;
for ( V_52 = 0 ; V_52 < 2 ; V_52 ++ ) {
struct V_50 * V_53 = & V_36 -> V_45 [ V_52 ] ;
struct V_47 * V_54 = & V_53 -> V_11 ;
V_53 -> V_36 = V_36 ;
snprintf ( V_53 -> V_34 , sizeof( V_53 -> V_34 ) , L_2 ,
F_21 ( V_11 ) , V_55 [ V_52 ] ) ;
V_54 -> V_34 = V_53 -> V_34 ;
V_54 -> V_46 = V_56 [ V_52 ] ;
V_54 -> V_57 = 0x26 ;
V_54 -> V_58 = F_18 ;
V_26 = F_22 ( V_11 , V_54 ) ;
if ( V_26 )
return V_26 ;
V_53 -> V_59 = true ;
}
return 0 ;
}
static void F_23 ( struct V_35 * V_36 )
{
struct V_50 * V_53 ;
int V_52 ;
for ( V_52 = 0 ; V_52 < 2 ; V_52 ++ ) {
V_53 = & V_36 -> V_45 [ V_52 ] ;
if ( ! V_53 -> V_59 )
break;
F_24 ( & V_53 -> V_11 ) ;
V_53 -> V_59 = false ;
}
}
static bool F_25 ( struct V_35 * V_36 )
{
switch ( V_36 -> type ) {
case V_60 :
case V_61 :
case V_62 :
case V_63 :
return true ;
default:
return false ;
}
}
static void F_26 ( struct V_35 * V_36 )
{
int V_64 ;
struct V_42 * V_37 = & V_36 -> V_37 ;
struct V_1 * V_2 = V_37 -> V_2 ;
V_64 = ( int ) F_27 () ;
F_28 ( V_37 , 0x80c6 , & V_64 , 4 ) ;
F_1 ( V_2 , 0x0301 , 0x0000 ) ;
if ( F_25 ( V_36 ) )
F_1 ( V_2 ,
V_29 [ V_36 -> V_38 ] . V_40 ,
0x0000 ) ;
if ( F_16 ( V_36 ) )
F_17 ( V_36 ) ;
F_29 ( & V_36 -> V_65 , V_66 + V_67 * V_10 ) ;
}
static void F_30 ( struct V_42 * V_37 )
{
struct V_35 * V_36 =
(struct V_35 * ) V_37 ;
F_31 ( & V_36 -> V_65 ) ;
if ( F_16 ( V_36 ) )
F_23 ( V_36 ) ;
}
static int F_32 ( struct V_42 * V_37 ,
const struct V_68 * V_69 )
{
int V_26 ;
struct V_35 * V_36 = (struct V_35 * ) V_37 ;
V_36 -> type = V_69 -> V_70 ;
F_33 ( & V_36 -> V_65 , F_15 ,
( unsigned long ) V_36 ) ;
V_37 -> V_71 = F_30 ;
V_26 = F_34 ( V_37 , & V_72 ) ;
if ( V_26 < 0 )
return V_26 ;
V_26 = F_35 ( V_37 -> V_73 ,
F_36 ( & V_74 ,
V_37 -> V_24 ) ) ;
if ( V_26 < 0 )
return V_26 ;
if ( F_25 ( V_36 ) ) {
V_26 =
F_35 ( V_37 -> V_73 ,
F_36 ( & V_75 ,
V_37 -> V_24 ) ) ;
if ( V_26 < 0 )
return V_26 ;
}
F_37 ( V_37 , & V_36 -> V_76 ) ;
F_38 ( V_37 , 0x80c2 , & V_36 -> V_77 , 1 ) ;
if ( F_16 ( V_36 ) ) {
V_26 = F_20 ( V_36 ) ;
if ( V_26 < 0 )
return V_26 ;
}
F_26 ( V_36 ) ;
return F_39 ( V_37 -> V_73 ) ;
}
static int F_40 ( struct V_78 * V_79 )
{
F_26 ( F_41 ( V_79 ) ) ;
return F_42 ( V_79 ) ;
}
static int F_43 ( struct V_78 * V_79 ,
const struct V_68 * V_69 )
{
return F_44 ( V_79 , V_69 , L_3 ,
& V_80 [ V_69 -> V_70 ] ,
F_32 , sizeof( struct V_35 ) ) ;
}
