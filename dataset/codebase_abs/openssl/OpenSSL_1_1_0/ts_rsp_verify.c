static T_1 * F_1 ( T_2 * V_1 )
{
T_3 * V_2 ;
const unsigned char * V_3 ;
V_2 = F_2 ( V_1 , V_4 ) ;
if ( ! V_2 )
return NULL ;
V_3 = V_2 -> V_5 . V_6 -> V_7 ;
return F_3 ( NULL , & V_3 , V_2 -> V_5 . V_6 -> V_8 ) ;
}
static int F_4 ( T_4 * V_9 , T_5 * V_10 )
{
T_6 * V_11 ;
if ( ! V_9 || ! V_10 || F_5 ( V_9 -> V_11 ) != 1 )
return - 1 ;
V_11 = F_6 ( V_9 -> V_11 , 0 ) ;
if ( V_11 -> type != V_12
|| F_7 ( V_11 -> V_13 . V_14 , F_8 ( V_10 ) ) )
return - 1 ;
if ( F_9 ( V_9 -> V_15 , F_10 ( V_10 ) ) )
return - 1 ;
return 0 ;
}
int F_11 ( T_7 * V_16 , T_8 * V_17 )
{
T_9 * V_18 = V_17 -> V_18 ;
T_10 * V_19 = V_17 -> V_19 ;
int V_20 = 0 ;
if ( ! F_12 ( V_17 ) )
goto V_21;
if ( ! F_13 ( V_16 , V_18 , V_19 ) )
goto V_21;
V_20 = 1 ;
V_21:
return V_20 ;
}
int F_14 ( T_7 * V_16 , T_9 * V_18 )
{
T_10 * V_19 = F_15 ( V_18 ) ;
int V_20 = 0 ;
if ( V_19 ) {
V_20 = F_13 ( V_16 , V_18 , V_19 ) ;
F_16 ( V_19 ) ;
}
return V_20 ;
}
static int F_13 ( T_7 * V_16 ,
T_9 * V_18 , T_10 * V_19 )
{
T_5 * V_22 = NULL ;
T_6 * V_23 = V_19 -> V_24 ;
T_11 * V_25 = NULL ;
unsigned char * V_26 = NULL ;
unsigned V_27 = 0 ;
int V_20 = 0 ;
int V_28 = V_16 -> V_28 ;
if ( ( ( V_28 & V_29 ) && V_23 != NULL )
|| ( V_28 & V_30 ) ) {
V_28 |= V_31 ;
}
if ( ( V_28 & V_31 )
&& ! F_17 ( V_18 , V_16 -> V_32 , V_16 -> V_33 , & V_22 ) )
goto V_21;
if ( ( V_28 & V_34 )
&& F_18 ( V_19 ) != 1 ) {
F_19 ( V_35 , V_36 ) ;
goto V_21;
}
if ( ( V_28 & V_37 )
&& ! F_20 ( V_16 -> V_38 , V_19 ) )
goto V_21;
if ( ( V_28 & V_39 )
&& ! F_21 ( V_16 -> V_25 , V_16 -> V_26 , V_16 -> V_27 ,
V_19 ) )
goto V_21;
if ( ( V_28 & V_40 )
&& ( ! F_22 ( V_16 -> V_7 , V_19 ,
& V_25 , & V_26 , & V_27 )
|| ! F_21 ( V_25 , V_26 , V_27 , V_19 ) ) )
goto V_21;
if ( ( V_28 & V_41 )
&& ! F_23 ( V_16 -> V_42 , V_19 ) )
goto V_21;
if ( ( V_28 & V_29 )
&& V_23 && ! F_24 ( V_23 , V_22 ) ) {
F_19 ( V_35 , V_43 ) ;
goto V_21;
}
if ( ( V_28 & V_30 )
&& ! F_24 ( V_16 -> V_23 , V_22 ) ) {
F_19 ( V_35 , V_44 ) ;
goto V_21;
}
V_20 = 1 ;
V_21:
F_25 ( V_22 ) ;
F_26 ( V_25 ) ;
F_27 ( V_26 ) ;
return V_20 ;
}
static int F_12 ( T_8 * V_17 )
{
T_12 * V_45 = V_17 -> V_46 ;
long V_47 = F_28 ( V_45 -> V_47 ) ;
const char * V_48 = NULL ;
char * V_49 = NULL ;
char V_50 [ V_51 ] = L_1 ;
if ( V_47 == 0 || V_47 == 1 )
return 1 ;
if ( 0 <= V_47 && V_47 < ( long ) F_29 ( V_52 ) )
V_48 = V_52 [ V_47 ] ;
else
V_48 = L_2 ;
if ( F_30 ( V_45 -> V_53 ) > 0
&& ( V_49 = F_31 ( V_45 -> V_53 ) ) == NULL )
return 0 ;
if ( V_45 -> V_54 ) {
int V_55 ;
int V_56 = 1 ;
for ( V_55 = 0 ; V_55 < ( int ) F_29 ( V_57 ) ; ++ V_55 ) {
if ( F_32 ( V_45 -> V_54 ,
V_57 [ V_55 ] . V_58 ) ) {
if ( ! V_56 )
strcat ( V_50 , L_3 ) ;
else
V_56 = 0 ;
strcat ( V_50 , V_57 [ V_55 ] . V_53 ) ;
}
}
}
if ( V_50 [ 0 ] == '\0' )
strcpy ( V_50 , L_4 ) ;
F_19 ( V_59 , V_60 ) ;
F_33 ( 6 ,
L_5 , V_48 ,
L_6 , V_49 ?
V_49 : L_4 ,
L_7 , V_50 ) ;
F_27 ( V_49 ) ;
return 0 ;
}
static int F_20 ( const T_13 * V_61 ,
const T_10 * V_19 )
{
const T_13 * V_62 = V_19 -> V_63 ;
if ( F_34 ( V_61 , V_62 ) != 0 ) {
F_19 ( V_64 , V_65 ) ;
return 0 ;
}
return 1 ;
}
static int F_22 ( T_14 * V_7 , T_10 * V_19 ,
T_11 * * V_25 ,
unsigned char * * V_26 , unsigned * V_27 )
{
T_15 * V_66 = V_19 -> V_66 ;
T_11 * V_67 = V_66 -> V_68 ;
const T_16 * V_69 ;
T_17 * V_70 = NULL ;
unsigned char V_71 [ 4096 ] ;
int V_8 ;
* V_25 = NULL ;
* V_26 = NULL ;
if ( ( * V_25 = F_35 ( V_67 ) ) == NULL )
goto V_21;
if ( ( V_69 = F_36 ( ( * V_25 ) -> V_72 ) ) == NULL ) {
F_19 ( V_73 , V_74 ) ;
goto V_21;
}
V_8 = F_37 ( V_69 ) ;
if ( V_8 < 0 )
goto V_21;
* V_27 = V_8 ;
if ( ( * V_26 = F_38 ( * V_27 ) ) == NULL ) {
F_19 ( V_73 , V_75 ) ;
goto V_21;
}
V_70 = F_39 () ;
if ( V_70 == NULL ) {
F_19 ( V_73 , V_75 ) ;
goto V_21;
}
if ( ! F_40 ( V_70 , V_69 ) )
goto V_21;
while ( ( V_8 = F_41 ( V_7 , V_71 , sizeof( V_71 ) ) ) > 0 ) {
if ( ! F_42 ( V_70 , V_71 , V_8 ) )
goto V_21;
}
if ( ! F_43 ( V_70 , * V_26 , NULL ) )
goto V_21;
F_44 ( V_70 ) ;
return 1 ;
V_21:
F_44 ( V_70 ) ;
F_26 ( * V_25 ) ;
F_27 ( * V_26 ) ;
* V_27 = 0 ;
* V_26 = 0 ;
return 0 ;
}
static int F_21 ( T_11 * V_76 ,
const unsigned char * V_77 , unsigned V_78 ,
T_10 * V_19 )
{
T_15 * V_79 = V_19 -> V_66 ;
T_11 * V_80 = V_79 -> V_68 ;
int V_20 = 0 ;
if ( V_76 ) {
if ( F_34 ( V_76 -> V_72 , V_80 -> V_72 ) )
goto V_21;
if ( ( V_76 -> V_81
&& F_45 ( V_76 -> V_81 ) != V_82 )
|| ( V_80 -> V_81
&& F_45 ( V_80 -> V_81 ) != V_82 ) )
goto V_21;
}
V_20 = V_78 == ( unsigned ) F_46 ( V_79 -> V_83 ) &&
memcmp ( V_77 , F_47 ( V_79 -> V_83 ) , V_78 ) == 0 ;
V_21:
if ( ! V_20 )
F_19 ( V_84 , V_85 ) ;
return V_20 ;
}
static int F_23 ( const T_18 * V_86 , T_10 * V_19 )
{
const T_18 * V_79 = V_19 -> V_42 ;
if ( ! V_79 ) {
F_19 ( V_87 , V_88 ) ;
return 0 ;
}
if ( F_9 ( V_86 , V_79 ) != 0 ) {
F_19 ( V_87 , V_89 ) ;
return 0 ;
}
return 1 ;
}
static int F_24 ( T_6 * V_23 , T_5 * V_22 )
{
F_48 ( T_6 ) * V_90 = NULL ;
int V_91 = - 1 ;
int V_92 = 0 ;
if ( V_23 -> type == V_12
&& F_49 ( V_23 -> V_13 . V_14 , F_50 ( V_22 ) ) == 0 )
return 1 ;
V_90 = F_51 ( V_22 , V_93 , NULL , & V_91 ) ;
while ( V_90 != NULL ) {
V_92 = F_52 ( V_90 , V_23 ) >= 0 ;
if ( V_92 )
break;
F_53 ( V_90 ) ;
V_90 = F_51 ( V_22 , V_93 , NULL , & V_91 ) ;
}
F_53 ( V_90 ) ;
return V_92 ;
}
