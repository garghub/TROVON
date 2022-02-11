static bool F_1 ( short V_1 )
{
return
( V_1 == V_2 ) ||
( V_1 == V_3 ) ;
}
static void F_2 ( struct V_4 * V_5 )
{
struct V_6 * V_7 = F_3 ( V_5 ) ;
struct V_8 * V_9 = F_4 ( V_7 ) ;
struct V_10 * V_11 ;
if ( ! V_9 )
return;
V_11 = & V_9 -> V_11 ;
if ( V_11 )
F_5 ( V_11 -> V_12 , ( V_13 << 8 ) | 0x0002 ,
V_14 ) ;
}
static T_1 F_6 ( struct V_4 * V_5 ,
struct V_15 * V_16 ,
const char * V_17 , T_2 V_18 )
{
int V_19 ;
V_19 = F_7 ( V_17 , 10 , & V_13 ) ;
if ( V_19 )
return V_19 ;
F_2 ( V_5 ) ;
return V_18 ;
}
static T_1 F_8 ( struct V_4 * V_5 ,
struct V_15 * V_16 ,
const char * V_17 , T_2 V_18 )
{
int V_19 ;
V_19 = F_7 ( V_17 , 10 , & V_14 ) ;
if ( V_19 )
return V_19 ;
F_2 ( V_5 ) ;
return V_18 ;
}
static int F_5 ( struct V_20 * V_12 , int V_21 , int V_22 )
{
int V_23 ;
V_23 = F_9 ( V_12 , F_10 ( V_12 , 0 ) , 0x67 ,
V_24 | V_25 | V_26 ,
V_21 , V_22 , NULL , 0 , V_27 * V_28 ) ;
if ( V_23 < 0 ) {
F_11 ( & V_12 -> V_5 , L_1 , V_23 ) ;
return V_23 ;
}
return 0 ;
}
static int F_12 ( struct V_29 * V_30 ,
struct V_31 * V_32 )
{
V_32 -> type = V_33 ;
V_32 -> V_18 = 1 ;
V_32 -> V_34 . integer . V_35 = 0 ;
V_32 -> V_34 . integer . V_36 = 256 ;
return 0 ;
}
static int F_13 ( struct V_29 * V_30 ,
struct V_37 * V_38 )
{
struct V_39 * V_40 = F_14 ( V_30 ) ;
V_38 -> V_34 . integer . V_34 [ 0 ] = V_40 -> V_41 ;
return 0 ;
}
static int F_15 ( struct V_29 * V_30 ,
struct V_37 * V_38 )
{
struct V_39 * V_40 = F_14 ( V_30 ) ;
if ( V_38 -> V_34 . integer . V_34 [ 0 ] == V_40 -> V_41 )
return 0 ;
V_40 -> V_41 = V_38 -> V_34 . integer . V_34 [ 0 ] ;
if ( V_40 -> V_41 > 0 )
F_16 ( V_40 , V_42 ) ;
else
F_17 ( V_40 , V_42 ) ;
return 1 ;
}
static int F_18 ( struct V_29 * V_30 ,
struct V_31 * V_32 )
{
const int V_43 = F_19 ( V_44 ) ;
V_32 -> type = V_45 ;
V_32 -> V_18 = 1 ;
V_32 -> V_34 . V_46 . V_47 = V_43 ;
if ( V_32 -> V_34 . V_46 . V_48 >= V_43 )
V_32 -> V_34 . V_46 . V_48 = V_43 - 1 ;
strcpy ( V_32 -> V_34 . V_46 . V_49 ,
V_44 [ V_32 -> V_34 . V_46 . V_48 ] . V_49 ) ;
return 0 ;
}
static int F_20 ( struct V_29 * V_30 ,
struct V_37 * V_38 )
{
struct V_39 * V_40 = F_14 ( V_30 ) ;
struct V_8 * V_50 =
(struct V_8 * ) V_40 -> V_11 ;
V_38 -> V_34 . V_46 . V_48 [ 0 ] = V_50 -> V_51 ;
return 0 ;
}
static int F_21 ( struct V_29 * V_30 ,
struct V_37 * V_38 )
{
struct V_39 * V_40 = F_14 ( V_30 ) ;
struct V_8 * V_50 =
(struct V_8 * ) V_40 -> V_11 ;
if ( V_38 -> V_34 . V_46 . V_48 [ 0 ] == V_50 -> V_51 )
return 0 ;
V_50 -> V_51 = V_38 -> V_34 . V_46 . V_48 [ 0 ] ;
F_5 ( V_50 -> V_11 . V_12 ,
V_44 [ V_50 -> V_51 ] . V_52 , 0x0000 ) ;
return 1 ;
}
static void F_22 ( unsigned long V_53 )
{
struct V_8 * V_50 = (struct V_8 * ) V_53 ;
struct V_10 * V_11 = & V_50 -> V_11 ;
F_16 ( V_11 -> V_40 , V_42 ) ;
}
static void F_23 ( struct V_6 * V_7 )
{
struct V_8 * V_50 = F_4 ( V_7 ) ;
if ( V_50 == NULL )
return;
F_24 ( & V_50 -> V_11 ) ;
}
static void F_25 ( struct V_8 * V_50 )
{
int V_54 ;
struct V_10 * V_11 = & V_50 -> V_11 ;
struct V_20 * V_12 = V_11 -> V_12 ;
V_54 = ( int ) F_26 () ;
F_27 ( V_11 , 0x80c6 , & V_54 , 4 ) ;
F_5 ( V_12 , 0x0301 , 0x0000 ) ;
switch ( V_12 -> V_55 . V_56 ) {
case V_57 :
case V_58 :
case V_59 :
case V_60 :
F_5 ( V_12 ,
V_44 [ V_50 -> V_51 ] . V_52 ,
0x0000 ) ;
}
if ( F_1 ( V_12 -> V_55 . V_56 ) )
F_2 ( & V_12 -> V_5 ) ;
}
static int F_28 ( struct V_6 * V_7 ,
struct V_8 * V_50 )
{
int V_61 ;
struct V_10 * V_11 = & V_50 -> V_11 ;
struct V_20 * V_12 = V_11 -> V_12 ;
if ( ( V_7 == NULL ) || ( V_50 == NULL ) )
return - V_62 ;
V_61 = F_29 ( V_11 ) ;
if ( V_61 < 0 )
return V_61 ;
V_61 = F_30 ( V_11 , & V_63 ) ;
if ( V_61 < 0 )
return V_61 ;
V_61 = F_31 ( V_11 -> V_64 ,
F_32 ( & V_65 ,
V_11 -> V_40 ) ) ;
if ( V_61 < 0 )
return V_61 ;
switch ( V_12 -> V_55 . V_56 ) {
case V_57 :
case V_58 :
case V_59 :
case V_60 :
V_61 =
F_31 ( V_11 -> V_64 ,
F_32 ( & V_66 ,
V_11 -> V_40 ) ) ;
if ( V_61 < 0 )
return V_61 ;
}
V_61 = F_33 ( V_11 ) ;
if ( V_61 < 0 )
return V_61 ;
F_34 ( V_11 , & V_50 -> V_67 ) ;
F_35 ( V_11 , 0x80c2 , & V_50 -> V_68 , 1 ) ;
if ( F_1 ( V_12 -> V_55 . V_56 ) ) {
F_36 ( F_37
( & V_7 -> V_5 , & V_69 ) ) ;
F_36 ( F_37
( & V_7 -> V_5 , & V_70 ) ) ;
}
F_25 ( V_50 ) ;
F_38 ( & V_50 -> V_71 ) ;
V_50 -> V_71 . V_72 = V_73 + V_74 * V_28 ;
V_50 -> V_71 . V_75 = F_22 ;
V_50 -> V_71 . V_76 = ( unsigned long ) V_50 ;
F_39 ( & V_50 -> V_71 ) ;
return 0 ;
}
int F_40 ( struct V_6 * V_7 ,
struct V_8 * V_50 )
{
int V_61 = F_28 ( V_7 , V_50 ) ;
if ( V_61 < 0 )
F_23 ( V_7 ) ;
return V_61 ;
}
void F_41 ( struct V_8 * V_50 )
{
F_25 ( V_50 ) ;
}
void F_42 ( struct V_6 * V_7 )
{
struct V_8 * V_50 ;
if ( V_7 == NULL )
return;
V_50 = F_4 ( V_7 ) ;
F_43 ( & V_50 -> V_71 ) ;
if ( F_1 ( V_50 -> V_11 . V_12 -> V_55 . V_56 ) ) {
F_44 ( & V_7 -> V_5 , & V_69 ) ;
F_44 ( & V_7 -> V_5 , & V_70 ) ;
}
if ( V_50 != NULL ) {
struct V_39 * V_40 = V_50 -> V_11 . V_40 ;
if ( V_40 != NULL ) {
F_17 ( V_40 , V_42 ) ;
F_45 ( V_40 ) ;
}
}
F_23 ( V_7 ) ;
}
