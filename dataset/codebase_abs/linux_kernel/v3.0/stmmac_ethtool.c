static void F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
if ( ! V_6 -> V_7 -> V_8 )
strcpy ( V_4 -> V_9 , V_10 ) ;
else
strcpy ( V_4 -> V_9 , V_11 ) ;
strcpy ( V_4 -> V_12 , V_13 ) ;
V_4 -> V_14 [ 0 ] = '\0' ;
V_4 -> V_15 = V_16 ;
}
static int F_3 ( struct V_1 * V_2 ,
struct V_17 * V_18 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_19 * V_20 = V_6 -> V_21 ;
int V_22 ;
if ( V_20 == NULL ) {
F_4 ( L_1 ,
V_23 , V_2 -> V_24 ) ;
return - V_25 ;
}
if ( ! F_5 ( V_2 ) ) {
F_4 ( L_2
L_3 , V_2 -> V_24 ) ;
return - V_26 ;
}
V_18 -> V_27 = V_28 ;
F_6 ( & V_6 -> V_29 ) ;
V_22 = F_7 ( V_20 , V_18 ) ;
F_8 ( & V_6 -> V_29 ) ;
return V_22 ;
}
static int F_9 ( struct V_1 * V_2 ,
struct V_17 * V_18 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_19 * V_20 = V_6 -> V_21 ;
int V_22 ;
F_10 ( & V_6 -> V_29 ) ;
V_22 = F_11 ( V_20 , V_18 ) ;
F_12 ( & V_6 -> V_29 ) ;
return V_22 ;
}
static T_1 F_13 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
return V_6 -> V_30 ;
}
static void F_14 ( struct V_1 * V_2 , T_1 V_31 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
V_6 -> V_30 = V_31 ;
}
static int F_15 ( struct V_1 * V_2 )
{
if ( ! F_5 ( V_2 ) )
return - V_26 ;
return 0 ;
}
static int F_16 ( struct V_1 * V_2 )
{
return V_32 ;
}
static void F_17 ( struct V_1 * V_2 ,
struct V_33 * V_34 , void * V_35 )
{
int V_36 ;
T_1 * V_37 = ( T_1 * ) V_35 ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
memset ( V_37 , 0x0 , V_32 ) ;
if ( ! V_6 -> V_7 -> V_8 ) {
for ( V_36 = 0 ; V_36 < 12 ; V_36 ++ )
V_37 [ V_36 ] = F_18 ( V_6 -> V_38 + ( V_36 * 4 ) ) ;
for ( V_36 = 0 ; V_36 < 9 ; V_36 ++ )
V_37 [ V_36 + 12 ] =
F_18 ( V_6 -> V_38 + ( V_39 + ( V_36 * 4 ) ) ) ;
V_37 [ 22 ] = F_18 ( V_6 -> V_38 + V_40 ) ;
V_37 [ 23 ] = F_18 ( V_6 -> V_38 + V_41 ) ;
} else {
for ( V_36 = 0 ; V_36 < 55 ; V_36 ++ )
V_37 [ V_36 ] = F_18 ( V_6 -> V_38 + ( V_36 * 4 ) ) ;
for ( V_36 = 0 ; V_36 < 22 ; V_36 ++ )
V_37 [ V_36 + 55 ] =
F_18 ( V_6 -> V_38 + ( V_39 + ( V_36 * 4 ) ) ) ;
}
}
static void
F_19 ( struct V_1 * V_42 ,
struct V_43 * V_44 )
{
struct V_5 * V_6 = F_2 ( V_42 ) ;
F_10 ( & V_6 -> V_29 ) ;
V_44 -> V_45 = 0 ;
V_44 -> V_46 = 0 ;
V_44 -> V_47 = V_6 -> V_21 -> V_47 ;
if ( V_6 -> V_48 & V_49 )
V_44 -> V_45 = 1 ;
if ( V_6 -> V_48 & V_50 )
V_44 -> V_46 = 1 ;
F_12 ( & V_6 -> V_29 ) ;
}
static int
F_20 ( struct V_1 * V_42 ,
struct V_43 * V_44 )
{
struct V_5 * V_6 = F_2 ( V_42 ) ;
struct V_19 * V_20 = V_6 -> V_21 ;
int V_51 = V_52 ;
int V_53 = 0 ;
F_10 ( & V_6 -> V_29 ) ;
if ( V_44 -> V_45 )
V_51 |= V_49 ;
if ( V_44 -> V_46 )
V_51 |= V_50 ;
V_6 -> V_48 = V_51 ;
V_20 -> V_47 = V_44 -> V_47 ;
if ( V_20 -> V_47 ) {
if ( F_5 ( V_42 ) )
V_53 = F_21 ( V_20 ) ;
} else
V_6 -> V_54 -> V_55 -> V_48 ( V_6 -> V_38 , V_20 -> V_56 ,
V_6 -> V_48 , V_6 -> V_44 ) ;
F_12 ( & V_6 -> V_29 ) ;
return V_53 ;
}
static void F_22 ( struct V_1 * V_2 ,
struct V_57 * V_58 , T_2 * V_59 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_36 ;
V_6 -> V_54 -> V_60 -> V_61 ( & V_2 -> V_62 , ( void * ) & V_6 -> V_63 ,
V_6 -> V_38 ) ;
for ( V_36 = 0 ; V_36 < V_16 ; V_36 ++ ) {
char * V_64 = ( char * ) V_6 + V_65 [ V_36 ] . V_66 ;
V_59 [ V_36 ] = ( V_65 [ V_36 ] . V_67 ==
sizeof( T_2 ) ) ? ( * ( T_2 * ) V_64 ) : ( * ( T_1 * ) V_64 ) ;
}
}
static int F_23 ( struct V_1 * V_42 , int V_68 )
{
switch ( V_68 ) {
case V_69 :
return V_16 ;
default:
return - V_70 ;
}
}
static void F_24 ( struct V_1 * V_2 , T_1 V_71 , T_3 * V_59 )
{
int V_36 ;
T_3 * V_64 = V_59 ;
switch ( V_71 ) {
case V_69 :
for ( V_36 = 0 ; V_36 < V_16 ; V_36 ++ ) {
memcpy ( V_64 , V_65 [ V_36 ] . V_72 ,
V_73 ) ;
V_64 += V_73 ;
}
break;
default:
F_25 ( 1 ) ;
break;
}
}
static void F_26 ( struct V_1 * V_2 , struct V_74 * V_75 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
F_6 ( & V_6 -> V_29 ) ;
if ( F_27 ( V_6 -> V_76 ) ) {
V_75 -> V_77 = V_78 | V_79 ;
V_75 -> V_80 = V_6 -> V_80 ;
}
F_8 ( & V_6 -> V_29 ) ;
}
static int F_28 ( struct V_1 * V_2 , struct V_74 * V_75 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
T_1 V_81 = V_78 | V_79 ;
if ( ! F_27 ( V_6 -> V_76 ) )
return - V_82 ;
if ( V_75 -> V_80 & ~ V_81 )
return - V_82 ;
if ( V_75 -> V_80 ) {
F_29 ( L_4 ) ;
F_30 ( V_6 -> V_76 , 1 ) ;
F_31 ( V_2 -> V_83 ) ;
} else {
F_30 ( V_6 -> V_76 , 0 ) ;
F_32 ( V_2 -> V_83 ) ;
}
F_6 ( & V_6 -> V_29 ) ;
V_6 -> V_80 = V_75 -> V_80 ;
F_8 ( & V_6 -> V_29 ) ;
return 0 ;
}
void F_33 ( struct V_1 * V_42 )
{
F_34 ( V_42 , & V_84 ) ;
}
