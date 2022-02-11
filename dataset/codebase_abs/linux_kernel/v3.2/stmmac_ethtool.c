static void F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
if ( V_6 -> V_7 -> V_8 )
strcpy ( V_4 -> V_9 , V_10 ) ;
else
strcpy ( V_4 -> V_9 , V_11 ) ;
strcpy ( V_4 -> V_12 , V_13 ) ;
V_4 -> V_14 [ 0 ] = '\0' ;
}
static int F_3 ( struct V_1 * V_2 ,
struct V_15 * V_16 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_17 * V_18 = V_6 -> V_19 ;
int V_20 ;
if ( V_18 == NULL ) {
F_4 ( L_1 ,
V_21 , V_2 -> V_22 ) ;
return - V_23 ;
}
if ( ! F_5 ( V_2 ) ) {
F_4 ( L_2
L_3 , V_2 -> V_22 ) ;
return - V_24 ;
}
V_16 -> V_25 = V_26 ;
F_6 ( & V_6 -> V_27 ) ;
V_20 = F_7 ( V_18 , V_16 ) ;
F_8 ( & V_6 -> V_27 ) ;
return V_20 ;
}
static int F_9 ( struct V_1 * V_2 ,
struct V_15 * V_16 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_17 * V_18 = V_6 -> V_19 ;
int V_20 ;
F_10 ( & V_6 -> V_27 ) ;
V_20 = F_11 ( V_18 , V_16 ) ;
F_12 ( & V_6 -> V_27 ) ;
return V_20 ;
}
static T_1 F_13 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
return V_6 -> V_28 ;
}
static void F_14 ( struct V_1 * V_2 , T_1 V_29 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
V_6 -> V_28 = V_29 ;
}
static int F_15 ( struct V_1 * V_2 )
{
if ( ! F_5 ( V_2 ) )
return - V_24 ;
return 0 ;
}
static int F_16 ( struct V_1 * V_2 )
{
return V_30 ;
}
static void F_17 ( struct V_1 * V_2 ,
struct V_31 * V_32 , void * V_33 )
{
int V_34 ;
T_1 * V_35 = ( T_1 * ) V_33 ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
memset ( V_35 , 0x0 , V_30 ) ;
if ( ! V_6 -> V_7 -> V_8 ) {
for ( V_34 = 0 ; V_34 < 12 ; V_34 ++ )
V_35 [ V_34 ] = F_18 ( V_6 -> V_36 + ( V_34 * 4 ) ) ;
for ( V_34 = 0 ; V_34 < 9 ; V_34 ++ )
V_35 [ V_34 + 12 ] =
F_18 ( V_6 -> V_36 + ( V_37 + ( V_34 * 4 ) ) ) ;
V_35 [ 22 ] = F_18 ( V_6 -> V_36 + V_38 ) ;
V_35 [ 23 ] = F_18 ( V_6 -> V_36 + V_39 ) ;
} else {
for ( V_34 = 0 ; V_34 < 55 ; V_34 ++ )
V_35 [ V_34 ] = F_18 ( V_6 -> V_36 + ( V_34 * 4 ) ) ;
for ( V_34 = 0 ; V_34 < 22 ; V_34 ++ )
V_35 [ V_34 + 55 ] =
F_18 ( V_6 -> V_36 + ( V_37 + ( V_34 * 4 ) ) ) ;
}
}
static void
F_19 ( struct V_1 * V_40 ,
struct V_41 * V_42 )
{
struct V_5 * V_6 = F_2 ( V_40 ) ;
F_10 ( & V_6 -> V_27 ) ;
V_42 -> V_43 = 0 ;
V_42 -> V_44 = 0 ;
V_42 -> V_45 = V_6 -> V_19 -> V_45 ;
if ( V_6 -> V_46 & V_47 )
V_42 -> V_43 = 1 ;
if ( V_6 -> V_46 & V_48 )
V_42 -> V_44 = 1 ;
F_12 ( & V_6 -> V_27 ) ;
}
static int
F_20 ( struct V_1 * V_40 ,
struct V_41 * V_42 )
{
struct V_5 * V_6 = F_2 ( V_40 ) ;
struct V_17 * V_18 = V_6 -> V_19 ;
int V_49 = V_50 ;
int V_51 = 0 ;
F_10 ( & V_6 -> V_27 ) ;
if ( V_42 -> V_43 )
V_49 |= V_47 ;
if ( V_42 -> V_44 )
V_49 |= V_48 ;
V_6 -> V_46 = V_49 ;
V_18 -> V_45 = V_42 -> V_45 ;
if ( V_18 -> V_45 ) {
if ( F_5 ( V_40 ) )
V_51 = F_21 ( V_18 ) ;
} else
V_6 -> V_52 -> V_53 -> V_46 ( V_6 -> V_36 , V_18 -> V_54 ,
V_6 -> V_46 , V_6 -> V_42 ) ;
F_12 ( & V_6 -> V_27 ) ;
return V_51 ;
}
static void F_22 ( struct V_1 * V_2 ,
struct V_55 * V_56 , T_2 * V_57 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_34 , V_58 = 0 ;
if ( ! V_6 -> V_7 -> V_8 )
V_6 -> V_52 -> V_59 -> V_60 ( & V_2 -> V_61 ,
( void * ) & V_6 -> V_62 ,
V_6 -> V_36 ) ;
else {
if ( V_6 -> V_63 . V_64 ) {
F_23 ( V_6 -> V_36 , & V_6 -> V_65 ) ;
for ( V_34 = 0 ; V_34 < V_66 ; V_34 ++ ) {
char * V_67 ;
V_67 = ( char * ) V_6 + V_68 [ V_34 ] . V_69 ;
V_57 [ V_58 ++ ] = ( V_68 [ V_34 ] . V_70 ==
sizeof( T_2 ) ) ? ( * ( T_2 * ) V_67 ) :
( * ( T_1 * ) V_67 ) ;
}
}
}
for ( V_34 = 0 ; V_34 < V_71 ; V_34 ++ ) {
char * V_67 = ( char * ) V_6 + V_72 [ V_34 ] . V_69 ;
V_57 [ V_58 ++ ] = ( V_72 [ V_34 ] . V_70 ==
sizeof( T_2 ) ) ? ( * ( T_2 * ) V_67 ) : ( * ( T_1 * ) V_67 ) ;
}
}
static int F_24 ( struct V_1 * V_40 , int V_73 )
{
struct V_5 * V_6 = F_2 ( V_40 ) ;
int V_74 ;
switch ( V_73 ) {
case V_75 :
V_74 = V_71 ;
if ( V_6 -> V_63 . V_64 )
V_74 += V_66 ;
return V_74 ;
default:
return - V_76 ;
}
}
static void F_25 ( struct V_1 * V_2 , T_1 V_77 , T_3 * V_57 )
{
int V_34 ;
T_3 * V_67 = V_57 ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
switch ( V_77 ) {
case V_75 :
if ( V_6 -> V_63 . V_64 )
for ( V_34 = 0 ; V_34 < V_66 ; V_34 ++ ) {
memcpy ( V_67 , V_68 [ V_34 ] . V_78 ,
V_79 ) ;
V_67 += V_79 ;
}
for ( V_34 = 0 ; V_34 < V_71 ; V_34 ++ ) {
memcpy ( V_67 , V_72 [ V_34 ] . V_78 ,
V_79 ) ;
V_67 += V_79 ;
}
break;
default:
F_26 ( 1 ) ;
break;
}
}
static void F_27 ( struct V_1 * V_2 , struct V_80 * V_81 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
F_6 ( & V_6 -> V_27 ) ;
if ( F_28 ( V_6 -> V_82 ) ) {
V_81 -> V_83 = V_84 | V_85 ;
V_81 -> V_86 = V_6 -> V_86 ;
}
F_8 ( & V_6 -> V_27 ) ;
}
static int F_29 ( struct V_1 * V_2 , struct V_80 * V_81 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
T_1 V_87 = V_84 | V_85 ;
if ( ( V_6 -> V_88 ) && ( ! V_6 -> V_63 . V_89 ) )
V_81 -> V_86 &= ~ V_84 ;
if ( ! F_28 ( V_6 -> V_82 ) )
return - V_90 ;
if ( V_81 -> V_86 & ~ V_87 )
return - V_90 ;
if ( V_81 -> V_86 ) {
F_30 ( L_4 ) ;
F_31 ( V_6 -> V_82 , 1 ) ;
F_32 ( V_6 -> V_91 ) ;
} else {
F_31 ( V_6 -> V_82 , 0 ) ;
F_33 ( V_6 -> V_91 ) ;
}
F_6 ( & V_6 -> V_27 ) ;
V_6 -> V_86 = V_81 -> V_86 ;
F_8 ( & V_6 -> V_27 ) ;
return 0 ;
}
void F_34 ( struct V_1 * V_40 )
{
F_35 ( V_40 , & V_92 ) ;
}
