static void F_1 ( struct V_1 * V_1 )
{
struct V_2 * V_3 = (struct V_2 * ) V_1 -> V_4 ;
struct V_5 * V_6 = V_3 -> V_6 ;
if ( V_1 -> V_7 == - V_8 ) {
F_2 ( L_1 ,
V_1 -> V_7 , V_1 -> V_9 ) ;
return;
}
if ( ( V_1 -> V_9 > 0 ) && ( V_1 -> V_7 == 0 ) ) {
struct V_10 * V_11 = (struct V_10 * ) V_3 -> V_12 -> V_13 ;
F_3 ( V_11 ) ;
if ( V_1 -> V_9 >= V_11 -> V_14 ) {
V_3 -> V_12 -> V_15 = V_11 -> V_14 ;
if ( V_6 -> V_16 &&
( V_11 -> V_17 & V_18 ) ) {
V_3 -> V_12 -> V_19 =
V_6 -> V_16 +
( ( V_11 -> V_17 >> 8 ) & 3 ) ;
if ( ( ( int ) V_11 -> V_14 +
V_3 -> V_12 -> V_19 ) > V_1 -> V_9 ) {
F_2 ( L_2
L_3
L_4 ,
V_11 -> V_14 ,
V_3 -> V_12 -> V_19 ,
V_1 -> V_9 ) ;
goto V_20;
}
memcpy ( ( char * ) V_11 + V_3 -> V_12 -> V_19 ,
V_11 , sizeof( struct V_10 ) ) ;
} else
V_3 -> V_12 -> V_19 = 0 ;
F_4 ( V_6 -> V_21 , V_3 -> V_12 ) ;
V_3 -> V_12 = NULL ;
} else {
F_2 ( L_2
L_5 ,
V_11 -> V_14 , V_1 -> V_9 ) ;
}
} else
F_2 ( L_6 ,
V_1 -> V_7 , V_1 -> V_9 ) ;
V_20:
F_5 ( V_6 , V_3 ) ;
}
static int F_5 ( struct V_5 * V_6 ,
struct V_2 * V_3 )
{
if ( ! V_3 -> V_12 ) {
V_3 -> V_12 = F_6 ( V_6 -> V_21 ) ;
if ( ! V_3 -> V_12 ) {
F_2 ( L_7 ) ;
return - V_22 ;
}
}
F_7 (
& V_3 -> V_1 ,
V_6 -> V_23 ,
F_8 ( V_6 -> V_23 , 0x81 ) ,
V_3 -> V_12 -> V_13 ,
V_6 -> V_24 ,
F_1 ,
V_3
) ;
V_3 -> V_1 . V_25 = V_3 -> V_12 -> V_26 ;
V_3 -> V_1 . V_27 |= V_28 ;
return F_9 ( & V_3 -> V_1 , V_29 ) ;
}
static void F_10 ( struct V_5 * V_6 )
{
int V_30 ;
for ( V_30 = 0 ; V_30 < V_31 ; V_30 ++ ) {
F_11 ( & V_6 -> V_32 [ V_30 ] . V_1 ) ;
if ( V_6 -> V_32 [ V_30 ] . V_12 ) {
F_12 ( V_6 -> V_21 , V_6 -> V_32 [ V_30 ] . V_12 ) ;
V_6 -> V_32 [ V_30 ] . V_12 = NULL ;
}
}
}
static int F_13 ( struct V_5 * V_6 )
{
int V_30 , V_33 ;
for ( V_30 = 0 ; V_30 < V_31 ; V_30 ++ ) {
V_33 = F_5 ( V_6 , & V_6 -> V_32 [ V_30 ] ) ;
if ( V_33 < 0 ) {
F_2 ( L_8 ) ;
F_10 ( V_6 ) ;
break;
}
}
return V_33 ;
}
static int F_14 ( void * V_4 , void * V_34 , T_1 V_15 )
{
struct V_5 * V_6 = (struct V_5 * ) V_4 ;
int V_35 ;
F_3 ( (struct V_10 * ) V_34 ) ;
return F_15 ( V_6 -> V_23 , F_16 ( V_6 -> V_23 , 2 ) ,
V_34 , V_15 , & V_35 , 1000 ) ;
}
static inline char * F_17 ( int V_36 , int V_37 )
{
char * * V_38 = F_18 ( V_37 ) -> V_38 ;
return ( V_38 && V_38 [ V_36 ] ) ? V_38 [ V_36 ] : V_39 [ V_36 ] ;
}
static int F_19 ( struct V_40 * V_23 , int V_41 , int V_37 )
{
const struct V_42 * V_38 ;
T_2 * V_43 ;
int V_33 , V_35 ;
char * V_44 ;
if ( V_41 < V_45 || V_41 > V_46 ) {
F_2 ( L_9 , V_41 ) ;
return - V_47 ;
}
V_44 = F_17 ( V_41 , V_37 ) ;
V_33 = F_20 ( & V_38 , V_44 , & V_23 -> V_6 ) ;
if ( V_33 < 0 ) {
F_21 ( L_10
L_11 , V_44 , V_41 ) ;
V_44 = V_39 [ V_41 ] ;
V_33 = F_20 ( & V_38 , V_44 , & V_23 -> V_6 ) ;
if ( V_33 < 0 ) {
F_21 ( L_12 ,
V_44 , V_41 ) ;
return V_33 ;
}
}
V_43 = F_22 ( V_38 -> V_15 , V_48 ) ;
if ( V_43 ) {
memcpy ( V_43 , V_38 -> V_49 , V_38 -> V_15 ) ;
V_33 = F_15 ( V_23 , F_16 ( V_23 , 2 ) ,
V_43 , V_38 -> V_15 , & V_35 , 1000 ) ;
F_23 ( L_13 , V_38 -> V_15 , V_35 , V_33 ) ;
F_24 ( V_43 ) ;
} else {
F_2 ( L_14 ) ;
V_33 = - V_22 ;
}
F_23 ( L_15 , V_44 , V_38 -> V_15 ) ;
F_25 ( V_38 ) ;
return V_33 ;
}
static void F_26 ( void * V_4 , int * V_36 )
{
char * V_50 =
( (struct V_5 * ) V_4 ) -> V_23 -> V_51 ;
* V_36 = V_52 ;
if ( ! V_50 ) {
V_50 = L_16 ;
F_2 ( L_17 ) ;
} else if ( strstr ( V_50 , L_18 ) )
* V_36 = 1 ;
else if ( strstr ( V_50 , L_19 ) )
* V_36 = 4 ;
else if ( strstr ( V_50 , L_20 ) )
* V_36 = 0 ;
else if ( strstr ( V_50 , L_21 ) )
* V_36 = 2 ;
F_23 ( L_22 , * V_36 , V_50 ) ;
}
static int F_27 ( void * V_4 , int V_36 )
{
struct V_10 V_53 = { V_54 , 0 , V_55 ,
sizeof( struct V_10 ) , 0 } ;
if ( V_36 < V_45 || V_36 > V_46 ) {
F_2 ( L_9 , V_36 ) ;
return - V_47 ;
}
return F_14 ( V_4 , & V_53 , sizeof( V_53 ) ) ;
}
static void F_28 ( struct V_56 * V_57 )
{
struct V_5 * V_6 = F_29 ( V_57 ) ;
if ( V_6 ) {
F_10 ( V_6 ) ;
if ( V_6 -> V_21 )
F_30 ( V_6 -> V_21 ) ;
F_23 ( L_23 , V_6 ) ;
F_24 ( V_6 ) ;
}
F_31 ( V_57 , NULL ) ;
}
static int F_32 ( struct V_56 * V_57 , int V_37 )
{
struct V_58 V_59 ;
struct V_5 * V_6 ;
int V_30 , V_33 ;
V_6 = F_33 ( sizeof( struct V_5 ) , V_48 ) ;
if ( ! V_6 ) {
F_2 ( L_24 ) ;
return - V_22 ;
}
memset ( & V_59 , 0 , sizeof( V_59 ) ) ;
F_31 ( V_57 , V_6 ) ;
V_6 -> V_23 = F_34 ( V_57 ) ;
V_59 . V_60 = F_18 ( V_37 ) -> type ;
switch ( V_59 . V_60 ) {
case V_61 :
V_6 -> V_24 = V_62 ;
V_59 . V_63 = F_27 ;
V_59 . V_64 = F_26 ;
break;
default:
F_2 ( L_25 ) ;
case V_65 :
case V_66 :
case V_67 :
V_6 -> V_24 = V_68 ;
V_6 -> V_16 =
F_35 ( V_6 -> V_23 -> V_69 [ 1 ] -> V_70 . V_71 ) -
sizeof( struct V_10 ) ;
V_59 . V_72 |= V_73 ;
break;
}
V_59 . V_74 = & V_6 -> V_23 -> V_6 ;
V_59 . V_24 = V_6 -> V_24 ;
V_59 . V_75 = V_76 ;
V_59 . V_77 = F_14 ;
V_59 . V_4 = V_6 ;
F_36 ( V_6 -> V_23 , V_59 . V_78 , sizeof( V_59 . V_78 ) ) ;
V_33 = F_37 ( & V_59 , & V_6 -> V_21 ) ;
if ( V_33 < 0 ) {
F_2 ( L_26 , V_33 ) ;
F_28 ( V_57 ) ;
return V_33 ;
}
F_38 ( V_6 -> V_21 , V_37 ) ;
for ( V_30 = 0 ; V_30 < V_31 ; V_30 ++ ) {
V_6 -> V_32 [ V_30 ] . V_6 = V_6 ;
F_39 ( & V_6 -> V_32 [ V_30 ] . V_1 ) ;
}
F_23 ( L_27 ) ;
V_33 = F_13 ( V_6 ) ;
if ( V_33 < 0 ) {
F_2 ( L_28 ) ;
F_28 ( V_57 ) ;
return V_33 ;
}
V_33 = F_40 ( V_6 -> V_21 ) ;
if ( V_33 < 0 ) {
F_2 ( L_29 ) ;
F_28 ( V_57 ) ;
return V_33 ;
}
F_23 ( L_30 , V_6 ) ;
return V_33 ;
}
static int T_3 F_41 ( struct V_56 * V_57 ,
const struct V_79 * V_41 )
{
struct V_40 * V_23 = F_34 ( V_57 ) ;
char V_78 [ 32 ] ;
int V_30 , V_33 ;
V_33 = F_42 ( V_23 , F_8 ( V_23 , 0x81 ) ) ;
V_33 = F_42 ( V_23 , F_8 ( V_23 , 0x02 ) ) ;
if ( V_57 -> V_80 > 0 ) {
V_33 = F_43 (
V_23 , V_57 -> V_81 -> V_70 . V_82 , 0 ) ;
if ( V_33 < 0 ) {
F_2 ( L_31 , V_33 ) ;
return V_33 ;
}
}
F_23 ( L_32 ,
V_57 -> V_81 -> V_70 . V_82 ) ;
for ( V_30 = 0 ; V_30 < V_57 -> V_81 -> V_70 . V_83 ; V_30 ++ )
F_23 ( L_33 , V_30 ,
V_57 -> V_81 -> V_84 [ V_30 ] . V_70 . V_85 ,
V_57 -> V_81 -> V_84 [ V_30 ] . V_70 . V_86 ,
V_57 -> V_81 -> V_84 [ V_30 ] . V_70 . V_71 ) ;
if ( ( V_23 -> V_87 -> V_70 . V_88 == 2 ) &&
( V_57 -> V_81 -> V_70 . V_82 == 0 ) ) {
F_2 ( L_34 ) ;
return - V_89 ;
}
if ( V_57 -> V_81 -> V_70 . V_82 == 1 ) {
snprintf ( V_78 , sizeof( V_78 ) , L_35 ,
V_23 -> V_90 -> V_91 , V_23 -> V_78 ) ;
F_23 ( L_36 ) ;
return F_19 (
V_23 , F_44 ( V_78 ) ,
V_41 -> V_92 ) ;
}
V_33 = F_32 ( V_57 , V_41 -> V_92 ) ;
F_23 ( L_37 , V_33 ) ;
F_45 ( V_41 -> V_92 ) ;
return V_33 ;
}
static void F_46 ( struct V_56 * V_57 )
{
F_28 ( V_57 ) ;
}
static int F_47 ( struct V_56 * V_57 , T_4 V_93 )
{
struct V_5 * V_6 = F_29 ( V_57 ) ;
F_48 ( V_94 L_38 , V_95 , V_93 . V_96 ) ;
F_10 ( V_6 ) ;
return 0 ;
}
static int F_49 ( struct V_56 * V_57 )
{
int V_33 , V_30 ;
struct V_5 * V_6 = F_29 ( V_57 ) ;
struct V_40 * V_23 = F_34 ( V_57 ) ;
F_48 ( V_94 L_39 , V_95 ) ;
F_42 ( V_23 , F_8 ( V_23 , 0x81 ) ) ;
F_42 ( V_23 , F_8 ( V_23 , 0x02 ) ) ;
for ( V_30 = 0 ; V_30 < V_57 -> V_81 -> V_70 . V_83 ; V_30 ++ )
F_48 ( V_94 L_40 , V_30 ,
V_57 -> V_81 -> V_84 [ V_30 ] . V_70 . V_85 ,
V_57 -> V_81 -> V_84 [ V_30 ] . V_70 . V_86 ,
V_57 -> V_81 -> V_84 [ V_30 ] . V_70 . V_71 ) ;
if ( V_57 -> V_80 > 0 ) {
V_33 = F_43 ( V_23 ,
V_57 -> V_81 -> V_70 .
V_82 , 0 ) ;
if ( V_33 < 0 ) {
F_48 ( V_94 L_41
L_42 , V_95 , V_33 ) ;
return V_33 ;
}
}
F_13 ( V_6 ) ;
return 0 ;
}
