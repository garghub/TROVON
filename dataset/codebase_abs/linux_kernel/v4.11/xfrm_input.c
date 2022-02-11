int F_1 ( const struct V_1 * V_2 )
{
int V_3 = 0 ;
if ( F_2 ( V_2 -> V_4 >= F_3 ( V_1 ) ) )
return - V_5 ;
F_4 ( & V_6 ) ;
if ( F_5 ( V_1 [ V_2 -> V_4 ] != NULL ) )
V_3 = - V_7 ;
else
F_6 ( V_1 [ V_2 -> V_4 ] , V_2 ) ;
F_7 ( & V_6 ) ;
return V_3 ;
}
int F_8 ( const struct V_1 * V_2 )
{
int V_3 = 0 ;
F_4 ( & V_6 ) ;
if ( F_9 ( V_1 [ V_2 -> V_4 ] != NULL ) ) {
if ( F_5 ( V_1 [ V_2 -> V_4 ] != V_2 ) )
V_3 = - V_8 ;
else
F_10 ( V_1 [ V_2 -> V_4 ] , NULL ) ;
}
F_7 ( & V_6 ) ;
F_11 () ;
return V_3 ;
}
static const struct V_1 * F_12 ( unsigned int V_4 )
{
const struct V_1 * V_2 ;
if ( F_13 ( V_4 >= F_3 ( V_1 ) ) )
return NULL ;
F_14 () ;
V_2 = F_15 ( V_1 [ V_4 ] ) ;
if ( F_5 ( ! V_2 ) )
F_16 () ;
return V_2 ;
}
static int F_17 ( struct V_9 * V_10 , unsigned int V_4 , T_1 V_11 ,
int V_3 )
{
int V_12 ;
const struct V_1 * V_2 = F_12 ( V_4 ) ;
if ( ! V_2 )
return - V_5 ;
V_12 = V_2 -> V_13 ( V_10 , V_11 , V_3 ) ;
F_16 () ;
return V_12 ;
}
void F_18 ( struct V_14 * V_15 )
{
int V_16 ;
for ( V_16 = 0 ; V_16 < V_15 -> V_17 ; V_16 ++ )
F_19 ( V_15 -> V_18 [ V_16 ] ) ;
F_20 ( V_19 , V_15 ) ;
}
struct V_14 * F_21 ( struct V_14 * V_20 )
{
struct V_14 * V_15 ;
V_15 = F_22 ( V_19 , V_21 ) ;
if ( ! V_15 )
return NULL ;
V_15 -> V_17 = 0 ;
V_15 -> V_22 = 0 ;
if ( V_20 ) {
int V_16 ;
memcpy ( V_15 , V_20 , sizeof( * V_15 ) ) ;
for ( V_16 = 0 ; V_16 < V_15 -> V_17 ; V_16 ++ )
F_23 ( V_15 -> V_18 [ V_16 ] ) ;
}
F_24 ( & V_15 -> V_23 , 1 ) ;
return V_15 ;
}
int F_25 ( struct V_9 * V_10 )
{
struct V_14 * V_15 ;
if ( ! V_10 -> V_15 || F_26 ( & V_10 -> V_15 -> V_23 ) != 1 ) {
V_15 = F_21 ( V_10 -> V_15 ) ;
if ( ! V_15 )
return - V_24 ;
if ( V_10 -> V_15 )
F_27 ( V_10 -> V_15 ) ;
V_10 -> V_15 = V_15 ;
}
return 0 ;
}
int F_28 ( struct V_9 * V_10 , T_1 V_25 , T_2 * V_26 , T_2 * V_27 )
{
int V_28 , V_29 ;
int V_30 ;
switch ( V_25 ) {
case V_31 :
V_30 = sizeof( struct V_32 ) ;
V_28 = F_29 ( struct V_32 , V_26 ) ;
V_29 = F_29 ( struct V_32 , V_33 ) ;
break;
case V_34 :
V_30 = sizeof( struct V_35 ) ;
V_28 = F_29 ( struct V_35 , V_26 ) ;
V_29 = F_29 ( struct V_35 , V_33 ) ;
break;
case V_36 :
if ( ! F_30 ( V_10 , sizeof( struct V_37 ) ) )
return - V_8 ;
* V_26 = F_31 ( F_32 ( * ( V_38 * ) ( F_33 ( V_10 ) + 2 ) ) ) ;
* V_27 = 0 ;
return 0 ;
default:
return 1 ;
}
if ( ! F_30 ( V_10 , V_30 ) )
return - V_8 ;
* V_26 = * ( T_2 * ) ( F_33 ( V_10 ) + V_28 ) ;
* V_27 = * ( T_2 * ) ( F_33 ( V_10 ) + V_29 ) ;
return 0 ;
}
int F_34 ( struct V_39 * V_40 , struct V_9 * V_10 )
{
struct V_41 * V_42 = V_40 -> V_42 ;
int V_3 ;
V_3 = V_40 -> V_43 -> V_2 -> V_44 ( V_40 , V_10 ) ;
if ( V_3 )
return V_3 ;
if ( V_40 -> V_45 . V_4 == V_46 ) {
V_42 = F_35 ( V_40 , F_36 ( V_10 ) -> V_11 ) ;
if ( V_42 == NULL )
return - V_5 ;
}
V_10 -> V_11 = V_42 -> V_2 -> V_47 ;
return V_42 -> V_48 ( V_40 , V_10 ) ;
}
int F_37 ( struct V_9 * V_10 , int V_25 , T_2 V_26 , int V_49 )
{
struct V_50 * V_50 = F_38 ( V_10 -> V_51 ) ;
int V_3 ;
T_2 V_27 ;
T_2 V_52 ;
struct V_39 * V_40 = NULL ;
T_3 * V_53 ;
struct V_41 * V_42 ;
T_4 V_54 = V_10 -> V_54 ;
unsigned int V_4 ;
int V_55 = 0 ;
int V_56 = 0 ;
struct V_57 * V_58 ;
bool V_59 = false ;
if ( V_49 < 0 ) {
V_40 = F_39 ( V_10 ) ;
V_4 = V_40 -> V_43 -> V_2 -> V_4 ;
if ( V_49 == - 1 ) {
V_56 = 1 ;
V_27 = F_40 ( V_10 ) -> V_27 . V_60 . V_61 ;
goto V_62;
}
V_49 = 0 ;
V_27 = F_41 ( V_10 ) -> V_27 ;
goto V_63;
}
V_53 = ( T_3 * ) ( F_42 ( V_10 ) +
F_41 ( V_10 ) -> V_64 ) ;
V_4 = F_41 ( V_10 ) -> V_4 ;
switch ( V_4 ) {
case V_65 :
if ( F_43 ( V_10 ) -> V_66 . V_67 )
V_54 = F_44 ( F_43 ( V_10 ) -> V_66 . V_67 -> V_68 . V_69 ) ;
break;
case V_70 :
if ( F_43 ( V_10 ) -> V_66 . V_71 )
V_54 = F_44 ( F_43 ( V_10 ) -> V_66 . V_71 -> V_68 . V_69 ) ;
break;
}
V_3 = F_25 ( V_10 ) ;
if ( V_3 ) {
F_45 ( V_50 , V_72 ) ;
goto V_73;
}
V_27 = 0 ;
if ( ! V_26 && ( V_3 = F_28 ( V_10 , V_25 , & V_26 , & V_27 ) ) != 0 ) {
F_45 ( V_50 , V_74 ) ;
goto V_73;
}
do {
if ( V_10 -> V_15 -> V_17 == V_75 ) {
F_45 ( V_50 , V_76 ) ;
goto V_73;
}
V_40 = F_46 ( V_50 , V_54 , V_53 , V_26 , V_25 , V_4 ) ;
if ( V_40 == NULL ) {
F_45 ( V_50 , V_77 ) ;
F_47 ( V_10 , V_4 , V_26 , V_27 ) ;
goto V_73;
}
V_10 -> V_15 -> V_18 [ V_10 -> V_15 -> V_17 ++ ] = V_40 ;
V_63:
F_48 ( & V_40 -> V_63 ) ;
if ( F_5 ( V_40 -> V_78 . V_79 != V_80 ) ) {
if ( V_40 -> V_78 . V_79 == V_81 )
F_45 ( V_50 , V_82 ) ;
else
F_45 ( V_50 ,
V_83 ) ;
goto V_84;
}
if ( ( V_40 -> V_85 ? V_40 -> V_85 -> V_49 : 0 ) != V_49 ) {
F_45 ( V_50 , V_86 ) ;
goto V_84;
}
if ( V_40 -> V_87 -> V_88 ( V_40 , V_10 , V_27 ) ) {
F_45 ( V_50 , V_89 ) ;
goto V_84;
}
if ( F_49 ( V_40 ) ) {
F_45 ( V_50 , V_90 ) ;
goto V_84;
}
F_50 ( & V_40 -> V_63 ) ;
if ( F_51 ( V_10 , V_40 , V_4 ) ) {
F_45 ( V_50 , V_91 ) ;
goto V_73;
}
V_52 = F_31 ( F_52 ( V_40 , V_27 ) ) ;
F_40 ( V_10 ) -> V_27 . V_60 . V_61 = V_27 ;
F_40 ( V_10 ) -> V_27 . V_60 . V_92 = V_52 ;
F_53 ( V_10 ) ;
F_54 ( V_10 -> V_51 ) ;
V_25 = V_40 -> type -> V_60 ( V_40 , V_10 ) ;
if ( V_25 == - V_93 )
return 0 ;
V_62:
F_55 ( V_10 -> V_51 ) ;
F_48 ( & V_40 -> V_63 ) ;
if ( V_25 <= 0 ) {
if ( V_25 == - V_94 ) {
F_56 ( V_40 , V_10 ,
V_40 -> type -> V_95 ) ;
V_40 -> V_96 . V_97 ++ ;
}
F_45 ( V_50 , V_98 ) ;
goto V_84;
}
V_49 = 0 ;
if ( V_56 && V_40 -> V_87 -> V_99 ( V_40 , V_10 , V_27 ) ) {
F_45 ( V_50 , V_89 ) ;
goto V_84;
}
V_40 -> V_87 -> V_100 ( V_40 , V_27 ) ;
V_40 -> V_101 . V_102 += V_10 -> V_17 ;
V_40 -> V_101 . V_103 ++ ;
F_50 ( & V_40 -> V_63 ) ;
F_36 ( V_10 ) -> V_11 = V_25 ;
V_42 = V_40 -> V_42 ;
if ( V_40 -> V_45 . V_4 == V_46 ) {
V_42 = F_35 ( V_40 , F_36 ( V_10 ) -> V_11 ) ;
if ( V_42 == NULL ) {
F_45 ( V_50 , V_91 ) ;
goto V_73;
}
}
if ( V_42 -> V_60 ( V_40 , V_10 ) ) {
F_45 ( V_50 , V_91 ) ;
goto V_73;
}
if ( V_40 -> V_43 -> V_104 & V_105 ) {
V_55 = 1 ;
break;
}
V_53 = & V_40 -> V_106 . V_53 ;
V_4 = V_40 -> V_43 -> V_2 -> V_4 ;
V_3 = F_28 ( V_10 , V_25 , & V_26 , & V_27 ) ;
if ( V_3 < 0 ) {
F_45 ( V_50 , V_74 ) ;
goto V_73;
}
} while ( ! V_3 );
V_3 = F_17 ( V_10 , V_4 , V_40 -> type -> V_95 , 0 ) ;
if ( V_3 )
goto V_73;
F_57 ( V_10 ) ;
if ( V_55 ) {
F_58 ( V_10 ) ;
F_59 ( & V_107 , V_10 ) ;
return 0 ;
} else {
V_58 = V_57 ( V_10 ) ;
if ( V_58 )
V_59 = V_58 -> V_104 & V_108 ;
V_3 = V_40 -> V_42 -> V_2 -> V_109 ( V_10 , V_59 || V_56 ) ;
if ( V_59 ) {
F_58 ( V_10 ) ;
F_59 ( & V_107 , V_10 ) ;
return V_3 ;
}
return V_3 ;
}
V_84:
F_50 ( & V_40 -> V_63 ) ;
V_73:
F_17 ( V_10 , V_4 , V_40 && V_40 -> type ? V_40 -> type -> V_95 : V_25 , - 1 ) ;
F_60 ( V_10 ) ;
return 0 ;
}
int F_61 ( struct V_9 * V_10 , int V_25 )
{
return F_37 ( V_10 , V_25 , 0 , - 1 ) ;
}
void T_5 F_62 ( void )
{
int V_3 ;
F_63 ( & V_110 ) ;
V_3 = F_64 ( & V_107 , & V_110 ) ;
if ( V_3 )
V_107 . V_111 = NULL ;
V_19 = F_65 ( L_1 ,
sizeof( struct V_14 ) ,
0 , V_112 | V_113 ,
NULL ) ;
}
