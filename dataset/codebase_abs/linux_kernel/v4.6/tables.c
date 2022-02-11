void F_1 ( struct V_1 * V_2 )
{
if ( ! V_2 )
return;
switch ( V_2 -> type ) {
case V_3 :
{
struct V_4 * V_5 =
(struct V_4 * ) V_2 ;
F_2 ( L_1 ,
V_5 -> V_6 , V_5 -> V_7 ,
( V_5 -> V_8 & V_9 ) ? L_2 : L_3 ) ;
}
break;
case V_10 :
{
struct V_11 * V_5 =
(struct V_11 * ) V_2 ;
F_2 ( L_4 ,
V_5 -> V_12 , V_5 -> V_13 ,
( V_5 -> V_8 & V_9 ) ? L_2 : L_3 ) ;
}
break;
case V_14 :
{
struct V_15 * V_5 =
(struct V_15 * ) V_2 ;
F_2 ( L_5 ,
V_5 -> V_7 , V_5 -> V_16 , V_5 -> V_17 ) ;
}
break;
case V_18 :
{
struct V_19 * V_5 =
(struct V_19 * ) V_2 ;
F_3 ( L_6 ,
V_5 -> V_20 , V_5 -> V_21 , V_5 -> V_22 ,
V_23 [ V_5 -> V_24 & V_25 ] ,
V_26 [ ( V_5 -> V_24 & V_27 ) >> 2 ] ) ;
if ( V_5 -> V_24 &
~ ( V_25 | V_27 ) )
F_3 ( L_7 ,
V_5 -> V_24 &
~ ( V_25 | V_27 ) ) ;
}
break;
case V_28 :
{
struct V_29 * V_5 =
(struct V_29 * ) V_2 ;
F_3 ( L_8 ,
V_23 [ V_5 -> V_24 & V_25 ] ,
V_26 [ ( V_5 -> V_24 & V_27 ) >> 2 ] ,
V_5 -> V_22 ) ;
}
break;
case V_30 :
{
struct V_31 * V_5 =
(struct V_31 * ) V_2 ;
F_3 ( L_9 ,
V_5 -> V_6 ,
V_23 [ V_5 -> V_24 & V_25 ] ,
V_26 [ ( V_5 -> V_24 & V_27 ) >> 2 ] ,
V_5 -> V_32 ) ;
}
break;
case V_33 :
{
T_1 V_34 , V_35 ;
struct V_36 * V_5 =
(struct V_36 * ) V_2 ;
V_34 = V_5 -> V_24 & V_25 ;
V_35 = ( V_5 -> V_24 & V_27 ) >> 2 ;
F_3 ( L_10 ,
V_5 -> V_13 ,
V_23 [ V_34 ] ,
V_26 [ V_35 ] ,
V_5 -> V_32 ) ;
}
break;
case V_37 :
{
struct V_38 * V_5 =
(struct V_38 * ) V_2 ;
F_3 ( L_11 ,
( void * ) ( unsigned long ) V_5 -> V_16 ) ;
}
break;
case V_39 :
{
struct V_40 * V_5 =
(struct V_40 * ) V_2 ;
F_2 ( L_12 ,
V_5 -> V_7 , ( void * ) ( unsigned long ) V_5 -> V_16 ,
V_5 -> V_17 ) ;
}
break;
case V_41 :
{
struct V_42 * V_5 =
(struct V_42 * ) V_2 ;
F_2 ( L_13 ,
V_5 -> V_6 , V_5 -> V_7 , V_5 -> V_43 ,
( V_5 -> V_8 & V_9 ) ? L_2 : L_3 ) ;
}
break;
case V_44 :
{
struct V_45 * V_5 =
(struct V_45 * ) V_2 ;
F_3 ( L_14 ,
V_23 [ V_5 -> V_24 & V_25 ] ,
V_26 [ ( V_5 -> V_24 & V_27 ) >> 2 ] ,
V_5 -> type , V_5 -> V_7 , V_5 -> V_43 , V_5 -> V_46 ,
V_5 -> V_22 ) ;
}
break;
case V_47 :
{
struct V_48 * V_5 =
(struct V_48 * ) V_2 ;
F_2 ( L_15 ,
V_5 -> V_13 , V_5 -> V_49 ,
V_5 -> V_50 ,
( V_5 -> V_51 & V_9 ) ? L_2 : L_3 ) ;
}
break;
case V_52 :
{
struct V_53 * V_5 =
(struct V_53 * ) V_2 ;
F_2 ( L_16 ,
V_5 -> V_54 , V_5 -> V_49 ,
V_5 -> V_17 ) ;
}
break;
default:
F_4 ( L_17 ,
V_2 -> type ) ;
break;
}
}
static int T_2
F_5 ( char * V_7 , unsigned long V_55 ,
struct V_56 * V_57 ,
struct V_58 * V_59 , int V_60 ,
unsigned int V_61 )
{
struct V_1 * V_62 ;
unsigned long V_63 ;
int V_64 = 0 ;
int V_65 ;
if ( V_66 )
return - V_67 ;
if ( ! V_7 )
return - V_68 ;
if ( ! V_55 )
return - V_68 ;
if ( ! V_57 ) {
F_4 ( L_18 , V_7 ) ;
return - V_67 ;
}
V_63 = ( unsigned long ) V_57 + V_57 -> V_69 ;
V_62 = (struct V_1 * )
( ( unsigned long ) V_57 + V_55 ) ;
while ( ( ( unsigned long ) V_62 ) + sizeof( struct V_1 ) <
V_63 ) {
if ( V_61 && V_64 >= V_61 )
break;
for ( V_65 = 0 ; V_65 < V_60 ; V_65 ++ ) {
if ( V_62 -> type != V_59 [ V_65 ] . V_7 )
continue;
if ( ! V_59 [ V_65 ] . V_70 ||
V_59 [ V_65 ] . V_70 ( V_62 , V_63 ) )
return - V_68 ;
V_59 -> V_64 ++ ;
break;
}
if ( V_65 != V_60 )
V_64 ++ ;
if ( V_62 -> V_69 == 0 ) {
F_6 ( L_19 , V_7 , V_59 -> V_7 ) ;
return - V_68 ;
}
V_62 = (struct V_1 * )
( ( unsigned long ) V_62 + V_62 -> V_69 ) ;
}
if ( V_61 && V_64 > V_61 ) {
F_4 ( L_20 ,
V_7 , V_59 -> V_7 , V_64 - V_61 , V_64 ) ;
}
return V_64 ;
}
int T_2
F_7 ( char * V_7 ,
unsigned long V_55 ,
T_3 V_70 ,
struct V_56 * V_57 ,
int V_71 , unsigned int V_61 )
{
struct V_58 V_59 = {
. V_7 = V_71 ,
. V_70 = V_70 ,
} ;
return F_5 ( V_7 , V_55 , V_57 ,
& V_59 , 1 , V_61 ) ;
}
int T_2
F_8 ( char * V_7 ,
unsigned long V_55 ,
struct V_58 * V_59 , int V_60 ,
unsigned int V_61 )
{
struct V_56 * V_57 = NULL ;
T_4 V_72 ;
int V_64 ;
T_5 V_73 = 0 ;
if ( V_66 )
return - V_67 ;
if ( ! V_7 )
return - V_68 ;
if ( ! strncmp ( V_7 , V_74 , 4 ) )
V_73 = V_75 ;
F_9 ( V_7 , V_73 , & V_57 , & V_72 ) ;
if ( ! V_57 ) {
F_4 ( L_18 , V_7 ) ;
return - V_67 ;
}
V_64 = F_5 ( V_7 , V_55 , V_57 ,
V_59 , V_60 , V_61 ) ;
F_10 ( ( char * ) V_57 , V_72 ) ;
return V_64 ;
}
int T_2
F_11 ( char * V_7 ,
unsigned long V_55 ,
int V_71 ,
T_3 V_70 ,
unsigned int V_61 )
{
struct V_58 V_59 = {
. V_7 = V_71 ,
. V_70 = V_70 ,
} ;
return F_8 ( V_7 , V_55 , & V_59 , 1 ,
V_61 ) ;
}
int T_2
F_12 ( enum V_76 V_7 ,
T_3 V_70 , unsigned int V_61 )
{
return F_11 ( V_74 ,
sizeof( struct V_77 ) , V_7 ,
V_70 , V_61 ) ;
}
int T_2 F_13 ( char * V_7 , T_6 V_70 )
{
struct V_56 * V_78 = NULL ;
T_4 V_72 ;
if ( V_66 )
return - V_67 ;
if ( ! V_7 || ! V_70 )
return - V_68 ;
if ( strncmp ( V_7 , V_74 , 4 ) == 0 )
F_9 ( V_7 , V_75 , & V_78 , & V_72 ) ;
else
F_9 ( V_7 , 0 , & V_78 , & V_72 ) ;
if ( V_78 ) {
V_70 ( V_78 ) ;
F_10 ( V_78 , V_72 ) ;
return 0 ;
} else
return - V_67 ;
}
static void T_2 F_14 ( void )
{
struct V_56 * V_78 = NULL ;
T_4 V_72 ;
F_9 ( V_74 , 2 , & V_78 , & V_72 ) ;
if ( V_78 ) {
F_4 ( L_21 ,
V_75 ) ;
F_4 ( L_22
L_23 ,
V_75 ? 0 : 2 ) ;
F_10 ( V_78 , V_72 ) ;
} else
V_75 = 0 ;
return;
}
int T_2 F_15 ( void )
{
T_7 V_79 ;
if ( V_80 ) {
F_3 ( L_24 ) ;
V_81 = TRUE ;
} else {
F_3 ( L_25 ) ;
V_81 = FALSE ;
}
V_79 = F_16 ( V_82 , V_83 , 0 ) ;
if ( F_17 ( V_79 ) )
return - V_68 ;
F_18 () ;
F_14 () ;
return 0 ;
}
static int T_2 F_19 ( char * V_84 )
{
if ( ! V_84 )
return - V_68 ;
if ( F_20 ( V_84 , 0 , & V_75 ) )
return - V_68 ;
F_21 ( L_26 , V_75 ) ;
return 0 ;
}
static int T_2 F_22 ( char * V_85 )
{
V_80 = true ;
return 0 ;
}
static int T_2 F_23 ( char * V_85 )
{
F_3 ( L_27 ) ;
V_86 = TRUE ;
return 0 ;
}
