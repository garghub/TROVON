static int F_1 ( struct V_1 * V_2 , T_1 V_3 ,
struct V_4 * * V_5 )
{
int V_6 ;
struct V_7 * V_8 ;
V_2 -> V_9 = F_2 ( V_3 , sizeof( struct V_7 * ) , V_10 ) ;
if ( ! V_2 -> V_9 )
return - V_11 ;
V_2 -> V_12 = F_2 ( V_3 , sizeof( struct V_7 ) , V_10 ) ;
if ( ! V_2 -> V_12 )
goto V_13;
F_3 ( & V_2 -> V_14 ) ;
F_4 ( & V_2 -> V_15 , ( void * ) V_2 -> V_9 , V_3 * sizeof( void * ) ) ;
for ( V_6 = 0 , V_8 = V_2 -> V_12 ; V_6 < V_3 ; V_6 ++ ) {
F_5 ( & V_2 -> V_15 , ( void * ) & V_8 , sizeof( void * ) ) ;
V_8 -> V_16 = V_5 [ V_6 ] ;
V_8 ++ ;
}
return 0 ;
F_6 ( V_2 -> V_12 ) ;
V_13:
F_6 ( V_2 -> V_9 ) ;
return - V_11 ;
}
static void F_7 ( struct V_1 * V_2 )
{
F_6 ( V_2 -> V_12 ) ;
F_6 ( V_2 -> V_9 ) ;
}
static struct V_4 * * F_8 ( struct V_17 * V_18 ,
T_1 V_3 , T_1 V_19 )
{
int V_6 ;
struct V_4 * * V_5 ;
V_5 = F_2 ( V_3 , sizeof( struct V_4 * ) , V_10 ) ;
if ( ! V_5 )
return NULL ;
for ( V_6 = 0 ; V_6 < V_3 ; V_6 ++ ) {
V_5 [ V_6 ] = F_9 ( sizeof( struct V_4 ) , V_10 ) ;
if ( ! V_5 [ V_6 ] )
goto V_20;
V_5 [ V_6 ] -> V_21 = F_10 ( V_18 , V_19 , & V_5 [ V_6 ] -> V_22 ,
V_10 ) ;
if ( ! V_5 [ V_6 ] -> V_21 )
goto V_20;
}
return V_5 ;
V_20:
for ( V_6 = 0 ; V_6 < V_3 && V_5 [ V_6 ] ; V_6 ++ ) {
if ( V_5 [ V_6 ] -> V_21 )
F_11 ( V_18 , V_19 , V_5 [ V_6 ] -> V_21 , V_5 [ V_6 ] -> V_22 ) ;
F_6 ( V_5 [ V_6 ] ) ;
}
F_6 ( V_5 ) ;
return NULL ;
}
static void F_12 ( struct V_17 * V_18 , struct V_4 * * V_5 , T_1 V_3 ,
T_1 V_19 )
{
int V_6 ;
for ( V_6 = 0 ; V_6 < V_3 ; V_6 ++ ) {
F_11 ( V_18 , V_19 , V_5 [ V_6 ] -> V_21 , V_5 [ V_6 ] -> V_22 ) ;
F_6 ( V_5 [ V_6 ] ) ;
}
F_6 ( V_5 ) ;
}
int F_13 ( struct V_23 * V_24 , struct V_17 * V_18 ,
T_1 V_25 , T_1 V_26 )
{
int V_27 ;
F_3 ( & V_24 -> V_14 ) ;
F_14 ( & V_24 -> V_28 ) ;
V_24 -> V_18 = V_18 ;
F_15 ( V_24 -> V_18 , V_24 ) ;
V_24 -> V_29 = V_26 ;
V_24 -> V_30 = V_25 ;
V_24 -> V_31 = F_8 ( V_24 -> V_18 , V_25 , V_26 ) ;
if ( ! V_24 -> V_31 )
return - V_11 ;
V_27 = F_1 ( & V_24 -> V_32 , V_25 , V_24 -> V_31 ) ;
if ( V_27 )
goto V_33;
return 0 ;
V_33:
F_12 ( V_24 -> V_18 , V_24 -> V_31 , V_25 , V_26 ) ;
return - V_11 ;
}
void F_16 ( struct V_23 * V_24 )
{
F_12 ( V_24 -> V_18 , V_24 -> V_31 , V_24 -> V_30 ,
V_24 -> V_29 ) ;
F_7 ( & V_24 -> V_32 ) ;
}
struct V_7 * F_17 ( struct V_23 * V_24 )
{
struct V_7 * V_8 = NULL ;
if ( F_18 ( & V_24 -> V_32 . V_15 , ( void * ) & V_8 ,
sizeof( void * ) , & V_24 -> V_32 . V_14 ) != sizeof( void * ) ) {
F_19 ( 1 , L_1 ) ;
return NULL ;
}
if ( ! V_8 )
return V_8 ;
V_8 -> V_24 = V_24 ;
F_14 ( & V_8 -> V_34 ) ;
V_8 -> V_35 = 0 ;
return V_8 ;
}
void F_20 ( struct V_7 * V_8 )
{
F_21 ( & V_8 -> V_24 -> V_32 . V_15 , ( void * ) & V_8 ,
sizeof( void * ) , & V_8 -> V_24 -> V_32 . V_14 ) ;
}
static int F_22 ( struct V_36 * V_37 , struct V_38 * V_39 ,
enum V_40 V_41 , T_2 V_42 ,
int V_43 , int V_44 )
{
struct V_7 * V_8 = NULL ;
struct V_45 * V_46 = NULL ;
int V_27 , V_47 = 0 , V_48 ;
if ( V_43 ) {
V_8 = (struct V_7 * ) V_37 -> V_49 . V_50 ;
V_46 = F_23 ( V_37 ) ;
F_24 ( L_2 , V_8 , F_25 ( V_37 ) ,
V_39 -> V_48 , F_26 ( V_37 ) ) ;
V_47 = F_27 ( V_8 -> V_24 -> V_18 , V_46 , F_26 ( V_37 ) ,
V_51 ) ;
if ( ! V_47 ) {
F_28 ( L_3 , V_8 , F_26 ( V_37 ) ) ;
return 0 ;
}
V_48 = F_29 ( F_25 ( V_37 ) , V_39 -> V_48 ) ;
} else
V_48 = V_39 -> V_48 ;
V_27 = V_42 ( V_37 , V_46 , V_47 , V_39 , 1 , V_41 , V_48 ) ;
if ( V_43 )
F_30 ( V_8 -> V_24 -> V_18 , V_46 , V_47 , V_51 ) ;
return V_27 ;
}
static int F_31 ( struct V_36 * V_37 , struct V_52 * V_53 ,
struct V_54 * V_55 ,
enum V_40 V_41 , T_2 V_42 ,
int V_43 , int V_44 )
{
struct V_7 * V_8 = NULL ;
struct V_38 * V_39 = NULL ;
struct V_45 V_56 , * V_46 = NULL ;
T_3 V_57 = 0 ;
int V_27 = 0 ;
int V_58 , V_47 = 0 , V_48 ;
if ( V_43 || V_44 ) {
V_8 = (struct V_7 * ) V_37 -> V_49 . V_50 ;
V_46 = F_23 ( V_37 ) ;
F_24 ( L_4 ,
V_8 , F_25 ( V_37 ) , V_55 -> V_48 ,
V_53 -> V_59 , V_53 -> V_60 ) ;
}
V_58 = V_55 -> V_61 . V_48 / sizeof( struct V_38 ) ;
if ( ( V_41 == V_62 && V_58 == V_53 -> V_59 ) ||
( V_41 == V_63 && V_58 == V_53 -> V_60 ) ) {
V_39 = & V_55 -> V_64 [ 0 ] ;
goto V_65;
}
if ( V_44 && V_43 ) {
V_39 = F_10 ( V_8 -> V_24 -> V_18 , V_55 -> V_61 . V_48 ,
& V_57 , V_10 ) ;
if ( ! V_39 ) {
F_32 ( L_5 , V_55 -> V_61 . V_48 ) ;
return - V_11 ;
}
F_33 ( & V_56 , V_39 , V_55 -> V_61 . V_48 ) ;
F_34 ( & V_56 ) = V_57 ;
F_35 ( & V_56 ) = V_55 -> V_61 . V_48 ;
V_27 = V_42 ( V_37 , & V_56 , 1 , & V_55 -> V_61 , 1 , V_63 ,
V_55 -> V_61 . V_48 ) ;
if ( V_27 ) {
F_32 ( L_6 , V_27 ) ;
goto V_66;
}
} else {
F_32 ( L_7 ) ;
return - V_67 ;
}
V_65:
if ( V_43 ) {
V_47 = F_27 ( V_8 -> V_24 -> V_18 , V_46 , F_26 ( V_37 ) ,
V_51 ) ;
if ( ! V_47 ) {
F_32 ( L_3 , V_8 , F_26 ( V_37 ) ) ;
V_27 = - V_68 ;
goto V_66;
}
V_48 = F_29 ( F_25 ( V_37 ) , V_55 -> V_48 ) ;
} else
V_48 = V_55 -> V_48 ;
V_27 = V_42 ( V_37 , V_46 , V_47 , V_39 , V_58 , V_41 , V_48 ) ;
if ( V_43 )
F_30 ( V_8 -> V_24 -> V_18 , V_46 , V_47 , V_51 ) ;
V_66:
if ( V_57 && V_43 )
F_11 ( V_8 -> V_24 -> V_18 , V_55 -> V_61 . V_48 , V_39 , V_57 ) ;
return V_27 ;
}
static int F_36 ( struct V_52 * V_53 )
{
int V_19 = 0 ;
T_4 V_69 = V_53 -> V_70 >> 4 ;
switch ( V_69 ) {
case V_71 :
break;
case V_72 :
V_19 = sizeof( struct V_38 ) ;
break;
case V_73 :
V_19 = sizeof( struct V_54 ) +
sizeof( struct V_38 ) * V_53 -> V_60 ;
break;
default:
F_32 ( L_8 , V_69 ) ;
break;
}
return V_19 ;
}
int F_37 ( struct V_36 * V_37 , struct V_52 * V_53 ,
T_2 V_42 , int V_43 , int V_44 )
{
struct V_38 * V_39 ;
struct V_54 * V_55 ;
enum V_40 V_41 ;
int V_74 , V_27 = 0 ;
T_4 V_75 ;
V_74 = V_53 -> V_76 & ~ 3 ;
V_41 = F_38 ( V_53 ) ;
if ( V_41 == V_62 )
V_74 += F_36 ( V_53 ) ;
if ( V_41 == V_63 )
V_75 = V_53 -> V_70 >> 4 ;
else
V_75 = V_53 -> V_70 & ( ( 1U << 4 ) - 1 ) ;
switch ( V_75 ) {
case V_71 :
break;
case V_72 :
V_39 = (struct V_38 * )
( V_53 -> V_77 + V_74 ) ;
V_27 = F_22 ( V_37 , V_39 , V_41 , V_42 , V_43 , V_44 ) ;
break;
case V_73 :
V_55 = (struct V_54 * )
( V_53 -> V_77 + V_74 ) ;
V_27 = F_31 ( V_37 , V_53 , V_55 , V_41 , V_42 , V_43 ,
V_44 ) ;
break;
default:
F_32 ( L_9 , V_41 , V_75 ) ;
V_27 = - V_67 ;
}
return V_27 ;
}
static int F_39 ( struct V_52 * V_53 , enum V_40 V_41 )
{
struct V_38 * V_39 ;
struct V_54 * V_55 ;
int V_48 = 0 , V_74 = V_53 -> V_76 & ~ 3 ;
T_4 V_69 ;
if ( V_41 == V_63 )
V_69 = V_53 -> V_70 >> 4 ;
else {
V_69 = V_53 -> V_70 & ( ( 1U << 4 ) - 1 ) ;
V_74 += F_36 ( V_53 ) ;
}
switch ( V_69 ) {
case V_71 :
break;
case V_72 :
V_39 = (struct V_38 * ) ( V_53 -> V_77 + V_74 ) ;
V_48 = V_39 -> V_48 ;
break;
case V_73 :
V_55 = (struct V_54 * ) ( V_53 -> V_77 + V_74 ) ;
V_48 = V_55 -> V_48 ;
break;
default:
F_32 ( L_10 , V_69 ) ;
break;
}
return V_48 ;
}
int F_40 ( struct V_78 * V_79 , struct V_52 * V_53 , void * V_80 ,
T_5 V_81 , T_5 V_82 )
{
enum V_40 V_41 ;
struct V_36 * V_37 ;
int V_83 , V_48 , V_27 ;
switch ( V_53 -> V_84 ) {
case V_85 :
V_83 = V_86 ;
break;
case V_87 :
V_83 = V_88 ;
break;
case V_89 :
V_83 = V_90 ;
break;
default:
F_32 ( L_11 , V_53 -> V_84 ) ;
V_83 = V_88 ;
}
V_41 = F_38 ( V_53 ) ;
V_48 = F_39 ( V_53 , V_41 ) ;
F_24 ( L_12 , V_80 , V_53 -> V_91 [ 0 ] ,
V_53 -> V_92 , V_41 , V_48 , V_83 , ( unsigned long long ) V_53 -> V_83 ) ;
V_37 = F_41 ( V_79 , V_41 , V_10 ) ;
if ( ! V_37 )
return - V_11 ;
V_37 -> V_49 . V_50 = V_80 ;
memcpy ( V_37 -> V_93 , V_53 -> V_91 , V_94 ) ;
V_37 -> V_95 . V_96 = V_48 ;
V_37 -> V_95 . V_97 . V_98 = ( void * ) ( unsigned long ) V_82 ;
V_37 -> V_83 = V_83 ;
V_27 = F_42 ( V_37 , V_81 , (struct V_99 * ) & V_53 -> V_92 ,
V_53 -> V_83 ) ;
if ( V_27 )
F_43 ( V_79 , V_37 ) ;
return V_27 ;
}
