int F_1 ( struct V_1 * V_2 )
{
int V_3 = 0 ;
if ( F_2 ( V_2 == NULL ) )
return - V_4 ;
if ( F_2 ( V_2 -> V_5 >= V_6 ) )
return - V_7 ;
F_3 ( & V_8 ) ;
if ( F_2 ( V_1 [ V_2 -> V_5 ] != NULL ) )
V_3 = - V_9 ;
else
F_4 ( V_1 [ V_2 -> V_5 ] , V_2 ) ;
F_5 ( & V_8 ) ;
return V_3 ;
}
int F_6 ( struct V_1 * V_2 )
{
int V_3 = 0 ;
if ( F_2 ( V_2 == NULL ) )
return - V_4 ;
if ( F_2 ( V_2 -> V_5 >= V_6 ) )
return - V_7 ;
F_3 ( & V_8 ) ;
if ( F_7 ( V_1 [ V_2 -> V_5 ] != NULL ) ) {
if ( F_2 ( V_1 [ V_2 -> V_5 ] != V_2 ) )
V_3 = - V_4 ;
else
F_8 ( V_1 [ V_2 -> V_5 ] , NULL ) ;
}
F_5 ( & V_8 ) ;
F_9 () ;
return V_3 ;
}
static struct V_1 * F_10 ( unsigned int V_5 )
{
struct V_1 * V_2 ;
if ( F_2 ( V_5 >= V_6 ) )
return NULL ;
F_11 () ;
V_2 = F_12 ( V_1 [ V_5 ] ) ;
if ( F_2 ( ! V_2 ) )
F_13 () ;
return V_2 ;
}
static void F_14 ( struct V_1 * V_2 )
{
F_13 () ;
}
static int F_15 ( struct V_10 * V_11 , unsigned int V_5 , T_1 V_12 ,
int V_3 )
{
int V_13 ;
struct V_1 * V_2 = F_10 ( V_5 ) ;
if ( ! V_2 )
return - V_7 ;
V_13 = V_2 -> V_14 ( V_11 , V_12 , V_3 ) ;
F_14 ( V_2 ) ;
return V_13 ;
}
void F_16 ( struct V_15 * V_16 )
{
int V_17 ;
for ( V_17 = 0 ; V_17 < V_16 -> V_18 ; V_17 ++ )
F_17 ( V_16 -> V_19 [ V_17 ] ) ;
F_18 ( V_20 , V_16 ) ;
}
struct V_15 * F_19 ( struct V_15 * V_21 )
{
struct V_15 * V_16 ;
V_16 = F_20 ( V_20 , V_22 ) ;
if ( ! V_16 )
return NULL ;
V_16 -> V_18 = 0 ;
if ( V_21 ) {
int V_17 ;
memcpy ( V_16 , V_21 , sizeof( * V_16 ) ) ;
for ( V_17 = 0 ; V_17 < V_16 -> V_18 ; V_17 ++ )
F_21 ( V_16 -> V_19 [ V_17 ] ) ;
}
F_22 ( & V_16 -> V_23 , 1 ) ;
return V_16 ;
}
int F_23 ( struct V_10 * V_11 , T_1 V_24 , T_2 * V_25 , T_2 * V_26 )
{
int V_27 , V_28 ;
int V_29 ;
switch ( V_24 ) {
case V_30 :
V_29 = sizeof( struct V_31 ) ;
V_27 = F_24 ( struct V_31 , V_25 ) ;
V_28 = F_24 ( struct V_31 , V_32 ) ;
break;
case V_33 :
V_29 = sizeof( struct V_34 ) ;
V_27 = F_24 ( struct V_34 , V_25 ) ;
V_28 = F_24 ( struct V_34 , V_32 ) ;
break;
case V_35 :
if ( ! F_25 ( V_11 , sizeof( struct V_36 ) ) )
return - V_4 ;
* V_25 = F_26 ( F_27 ( * ( V_37 * ) ( F_28 ( V_11 ) + 2 ) ) ) ;
* V_26 = 0 ;
return 0 ;
default:
return 1 ;
}
if ( ! F_25 ( V_11 , V_29 ) )
return - V_4 ;
* V_25 = * ( T_2 * ) ( F_28 ( V_11 ) + V_27 ) ;
* V_26 = * ( T_2 * ) ( F_28 ( V_11 ) + V_28 ) ;
return 0 ;
}
int F_29 ( struct V_38 * V_39 , struct V_10 * V_11 )
{
struct V_40 * V_41 = V_39 -> V_41 ;
int V_3 ;
V_3 = V_39 -> V_42 -> V_2 -> V_43 ( V_39 , V_11 ) ;
if ( V_3 )
return V_3 ;
if ( V_39 -> V_44 . V_5 == V_45 ) {
V_41 = F_30 ( V_39 , F_31 ( V_11 ) -> V_12 ) ;
if ( V_41 == NULL )
return - V_7 ;
}
V_11 -> V_12 = V_41 -> V_2 -> V_46 ;
return V_41 -> V_47 ( V_39 , V_11 ) ;
}
int F_32 ( struct V_10 * V_11 , int V_24 , T_2 V_25 , int V_48 )
{
struct V_49 * V_49 = F_33 ( V_11 -> V_50 ) ;
int V_3 ;
T_2 V_26 ;
T_2 V_51 ;
struct V_38 * V_39 = NULL ;
T_3 * V_52 ;
struct V_40 * V_41 ;
unsigned int V_5 ;
int V_53 = 0 ;
int V_54 = 0 ;
if ( V_48 < 0 ) {
V_54 = 1 ;
V_39 = F_34 ( V_11 ) ;
V_26 = F_35 ( V_11 ) -> V_26 . V_55 . V_56 ;
V_5 = V_39 -> V_42 -> V_2 -> V_5 ;
goto V_57;
}
V_52 = ( T_3 * ) ( F_36 ( V_11 ) +
F_37 ( V_11 ) -> V_58 ) ;
V_5 = F_37 ( V_11 ) -> V_5 ;
if ( ! V_11 -> V_16 || F_38 ( & V_11 -> V_16 -> V_23 ) != 1 ) {
struct V_15 * V_16 ;
V_16 = F_19 ( V_11 -> V_16 ) ;
if ( ! V_16 ) {
F_39 ( V_49 , V_59 ) ;
goto V_60;
}
if ( V_11 -> V_16 )
F_40 ( V_11 -> V_16 ) ;
V_11 -> V_16 = V_16 ;
}
V_26 = 0 ;
if ( ! V_25 && ( V_3 = F_23 ( V_11 , V_24 , & V_25 , & V_26 ) ) != 0 ) {
F_39 ( V_49 , V_61 ) ;
goto V_60;
}
do {
if ( V_11 -> V_16 -> V_18 == V_62 ) {
F_39 ( V_49 , V_63 ) ;
goto V_60;
}
V_39 = F_41 ( V_49 , V_11 -> V_64 , V_52 , V_25 , V_24 , V_5 ) ;
if ( V_39 == NULL ) {
F_39 ( V_49 , V_65 ) ;
F_42 ( V_11 , V_5 , V_25 , V_26 ) ;
goto V_60;
}
V_11 -> V_16 -> V_19 [ V_11 -> V_16 -> V_18 ++ ] = V_39 ;
if ( F_43 ( V_11 , V_39 , V_5 ) ) {
F_39 ( V_49 , V_66 ) ;
goto V_60;
}
F_44 ( & V_39 -> V_67 ) ;
if ( F_2 ( V_39 -> V_68 . V_69 == V_70 ) ) {
F_39 ( V_49 , V_71 ) ;
goto V_72;
}
if ( F_2 ( V_39 -> V_68 . V_69 != V_73 ) ) {
F_39 ( V_49 , V_74 ) ;
goto V_72;
}
if ( ( V_39 -> V_75 ? V_39 -> V_75 -> V_48 : 0 ) != V_48 ) {
F_39 ( V_49 , V_76 ) ;
goto V_72;
}
if ( V_39 -> V_77 -> V_78 ( V_39 , V_11 , V_26 ) ) {
F_39 ( V_49 , V_79 ) ;
goto V_72;
}
if ( F_45 ( V_39 ) ) {
F_39 ( V_49 , V_80 ) ;
goto V_72;
}
F_46 ( & V_39 -> V_67 ) ;
V_51 = F_26 ( F_47 ( V_39 , V_26 ) ) ;
F_35 ( V_11 ) -> V_26 . V_55 . V_56 = V_26 ;
F_35 ( V_11 ) -> V_26 . V_55 . V_81 = V_51 ;
F_48 ( V_11 ) ;
V_24 = V_39 -> type -> V_55 ( V_39 , V_11 ) ;
if ( V_24 == - V_82 )
return 0 ;
V_57:
F_44 ( & V_39 -> V_67 ) ;
if ( V_24 <= 0 ) {
if ( V_24 == - V_83 ) {
F_49 ( V_39 , V_11 ,
V_39 -> type -> V_84 ) ;
V_39 -> V_85 . V_86 ++ ;
}
F_39 ( V_49 , V_87 ) ;
goto V_72;
}
V_48 = 0 ;
if ( V_54 && V_39 -> V_77 -> V_88 ( V_39 , V_11 , V_26 ) ) {
F_39 ( V_49 , V_79 ) ;
goto V_72;
}
V_39 -> V_77 -> V_89 ( V_39 , V_26 ) ;
V_39 -> V_90 . V_91 += V_11 -> V_18 ;
V_39 -> V_90 . V_92 ++ ;
F_46 ( & V_39 -> V_67 ) ;
F_31 ( V_11 ) -> V_12 = V_24 ;
V_41 = V_39 -> V_41 ;
if ( V_39 -> V_44 . V_5 == V_45 ) {
V_41 = F_30 ( V_39 , F_31 ( V_11 ) -> V_12 ) ;
if ( V_41 == NULL )
goto V_60;
}
if ( V_41 -> V_55 ( V_39 , V_11 ) ) {
F_39 ( V_49 , V_66 ) ;
goto V_60;
}
if ( V_39 -> V_42 -> V_93 & V_94 ) {
V_53 = 1 ;
break;
}
V_52 = & V_39 -> V_95 . V_52 ;
V_5 = V_39 -> V_42 -> V_2 -> V_5 ;
V_3 = F_23 ( V_11 , V_24 , & V_25 , & V_26 ) ;
if ( V_3 < 0 ) {
F_39 ( V_49 , V_61 ) ;
goto V_60;
}
} while ( ! V_3 );
V_3 = F_15 ( V_11 , V_5 , V_39 -> type -> V_84 , 0 ) ;
if ( V_3 )
goto V_60;
F_50 ( V_11 ) ;
if ( V_53 ) {
F_51 ( V_11 ) ;
F_52 ( V_11 ) ;
return 0 ;
} else {
return V_39 -> V_41 -> V_2 -> V_96 ( V_11 , V_54 ) ;
}
V_72:
F_46 ( & V_39 -> V_67 ) ;
V_60:
F_15 ( V_11 , V_5 , V_39 && V_39 -> type ? V_39 -> type -> V_84 : V_24 , - 1 ) ;
F_53 ( V_11 ) ;
return 0 ;
}
int F_54 ( struct V_10 * V_11 , int V_24 )
{
return F_32 ( V_11 , V_24 , 0 , - 1 ) ;
}
void T_4 F_55 ( void )
{
V_20 = F_56 ( L_1 ,
sizeof( struct V_15 ) ,
0 , V_97 | V_98 ,
NULL ) ;
}
