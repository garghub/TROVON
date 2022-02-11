static inline int F_1 ( enum V_1 type )
{
if ( type == V_2 )
return sizeof( struct V_3 ) ;
else
return sizeof( struct V_4 ) ;
}
static inline T_1 F_2 ( enum V_1 type , void * V_5 )
{
if ( type == V_2 )
return ( (struct V_3 * ) V_5 ) -> V_6 ;
else
return ( (struct V_4 * ) V_5 ) -> V_6 ;
}
static inline T_1 F_3 ( enum V_1 type , void * V_5 )
{
if ( type == V_2 )
return ( (struct V_3 * ) V_5 ) -> V_7 ;
else
return ( (struct V_4 * ) V_5 ) -> V_7 ;
}
static inline T_2 F_4 ( enum V_1 type , void * V_5 )
{
if ( type == V_2 )
return ( (struct V_3 * ) V_5 ) -> V_8 ;
else
return ( (struct V_4 * ) V_5 ) -> V_8 ;
}
static inline int F_5 ( enum V_1 type )
{
if ( type == V_2 )
return sizeof( struct V_9 ) ;
else
return sizeof( struct V_10 ) ;
}
static inline T_1 F_6 ( enum V_1 type , void * V_5 )
{
if ( type == V_2 )
return ( (struct V_9 * ) V_5 ) -> V_11 ;
else
return ( (struct V_10 * ) V_5 ) -> V_12 ;
}
static inline void F_7 ( enum V_1 type , void * V_5 ,
char * V_13 )
{
if ( type == V_2 )
memcpy ( V_13 , ( (struct V_9 * ) V_5 ) -> V_14 ,
V_15 ) ;
else
memcpy ( V_13 , ( (struct V_10 * ) V_5 ) -> V_14 ,
V_15 ) ;
F_8 ( V_13 , V_15 ) ;
V_13 [ V_15 ] = 0 ;
F_9 ( V_13 ) ;
}
static inline int F_10 ( enum V_1 type )
{
if ( type == V_2 )
return sizeof( struct V_16 ) ;
else
return sizeof( struct V_17 ) ;
}
static inline T_1 F_11 ( enum V_1 type , void * V_5 )
{
if ( type == V_2 )
return ( (struct V_16 * ) V_5 ) -> V_18 ;
else
return ( (struct V_17 * ) V_5 ) -> V_18 ;
}
static inline T_2 F_12 ( enum V_1 type , void * V_5 )
{
if ( type == V_2 )
return ( (struct V_16 * ) V_5 ) -> V_19 ;
else
return ( (struct V_17 * ) V_5 ) -> V_19 ;
}
static inline T_3 F_13 ( enum V_1 type , void * V_5 )
{
if ( type == V_2 )
return ( (struct V_16 * ) V_5 ) -> V_20 ;
else
return ( (struct V_17 * ) V_5 ) -> V_20 ;
}
static inline T_3 F_14 ( enum V_1 type , void * V_5 )
{
if ( type == V_2 )
return ( (struct V_16 * ) V_5 ) -> V_21 ;
else
return ( (struct V_17 * ) V_5 ) -> V_21 ;
}
static inline T_3 F_15 ( enum V_1 type , void * V_5 )
{
if ( type == V_2 )
return 0 ;
else
return ( (struct V_17 * ) V_5 ) -> V_22 ;
}
static inline int F_16 ( enum V_1 type )
{
if ( type == V_2 )
return sizeof( struct V_23 ) ;
else
return sizeof( struct V_24 ) ;
}
static inline T_1 F_17 ( enum V_1 type , void * V_5 )
{
if ( type == V_2 )
return ( (struct V_23 * ) V_5 ) -> V_11 ;
else
return ( (struct V_24 * ) V_5 ) -> V_11 ;
}
static inline int F_18 ( enum V_1 type )
{
if ( type == V_2 )
return sizeof( struct V_25 ) ;
else
return sizeof( struct V_26 ) ;
}
static inline T_2 F_19 ( enum V_1 type , void * V_5 )
{
if ( type == V_2 )
return ( (struct V_25 * ) V_5 ) -> V_19 ;
else
return ( (struct V_26 * ) V_5 ) -> V_19 ;
}
static inline T_3 F_20 ( enum V_1 type , void * V_5 )
{
if ( type == V_2 )
return ( (struct V_25 * ) V_5 ) -> V_27 ;
else
return ( (struct V_26 * ) V_5 ) -> V_27 ;
}
static inline T_3 F_21 ( enum V_1 type , void * V_5 )
{
if ( type == V_2 )
return ( (struct V_25 * ) V_5 ) -> V_18 ;
else
return ( (struct V_26 * ) V_5 ) -> V_18 ;
}
static void F_22 ( void )
{
if ( ! V_28 )
return;
if ( V_29 ) {
F_23 ( V_29 ) ;
V_29 = NULL ;
} else {
F_24 ( ( unsigned long ) V_28 , 0 ) ;
}
V_28 = NULL ;
}
static void * F_25 ( void * V_30 )
{
return ( void * ) F_26 ( ( unsigned long ) V_30 ) ;
}
static void * F_27 ( int V_31 )
{
V_29 = F_28 ( V_32 * ( V_31 + 1 ) ) ;
if ( ! V_29 )
return F_29 ( - V_33 ) ;
V_28 = F_25 ( V_29 ) ;
V_34 = V_31 ;
return V_28 ;
}
static void * F_30 ( void )
{
V_28 = ( void * ) F_31 ( V_35 , 0 ) ;
if ( ! V_28 )
return F_29 ( - V_33 ) ;
V_34 = 1 ;
return V_28 ;
}
static void * F_32 ( enum V_1 V_36 , int * V_31 )
{
if ( V_28 ) {
* V_31 = V_34 ;
return V_28 ;
}
if ( V_36 == V_2 ) {
* V_31 = 1 ;
return F_30 () ;
} else {
* V_31 = F_33 ( ( unsigned long ) V_37 |
( unsigned long ) V_38 , 0 , NULL ) ;
if ( * V_31 <= 0 )
return F_29 ( - V_39 ) ;
else
return F_27 ( * V_31 ) ;
}
}
static int F_34 ( void )
{
void * V_40 ;
int V_31 , V_41 ;
V_40 = F_32 ( V_38 , & V_31 ) ;
if ( ! F_35 ( V_40 ) ) {
if ( F_33 ( ( unsigned long ) V_42 |
( unsigned long ) V_38 , V_31 , V_40 ) >= 0 ) {
V_43 = V_42 ;
V_44 = V_38 ;
goto V_45;
}
if ( F_33 ( ( unsigned long ) V_46 |
( unsigned long ) V_38 , V_31 , V_40 ) >= 0 ) {
V_43 = V_46 ;
V_44 = V_38 ;
goto V_45;
}
F_22 () ;
}
V_40 = F_32 ( V_2 , & V_31 ) ;
if ( F_35 ( V_40 ) ) {
V_41 = F_36 ( V_40 ) ;
goto V_47;
}
if ( F_33 ( ( unsigned long ) V_48 |
( unsigned long ) V_2 , V_31 , V_40 ) >= 0 ) {
V_43 = V_48 ;
V_44 = V_2 ;
goto V_45;
} else {
V_41 = - V_39 ;
goto V_49;
}
V_45:
V_41 = 0 ;
V_49:
F_22 () ;
V_47:
return V_41 ;
}
static int F_37 ( void * V_40 , int V_31 )
{
int V_41 ;
V_41 = F_33 ( ( unsigned long ) V_43 |
( unsigned long ) V_44 , V_31 , V_40 ) ;
return V_41 < 0 ? - V_39 : 0 ;
}
static void * F_38 ( void )
{
void * V_40 ;
int V_31 , V_41 ;
V_40 = F_32 ( V_44 , & V_31 ) ;
if ( F_35 ( V_40 ) )
goto V_45;
V_41 = F_37 ( V_40 , V_31 ) ;
if ( V_41 )
return F_29 ( V_41 ) ;
V_45:
return V_40 ;
}
static int F_39 ( void )
{
V_50 = ( char * ) F_40 ( V_35 | V_51 ) ;
if ( ! V_50 )
return - V_33 ;
if ( F_41 ( V_50 ) ) {
F_42 ( ( unsigned long ) V_50 ) ;
return - V_52 ;
}
F_8 ( V_50 + 16 , ( * V_50 + 1 ) * 16 ) ;
return 0 ;
}
static void F_43 ( void )
{
F_42 ( ( unsigned long ) V_50 ) ;
}
static int F_44 ( int V_53 , char * V_13 )
{
memcpy ( V_13 , V_50 + ( ( V_53 + 1 ) * V_54 ) ,
V_54 ) ;
V_13 [ V_54 ] = 0 ;
F_9 ( V_13 ) ;
return 0 ;
}
static int F_45 ( void * * V_55 , void * * V_56 , T_4 * V_57 )
{
struct V_58 * V_59 ;
int V_41 , V_60 ;
void * V_61 ;
V_60 = V_32 * ( V_34 + 1 ) + sizeof( V_59 -> V_5 ) ;
V_61 = F_46 ( V_60 ) ;
if ( ! V_61 )
return - V_33 ;
V_59 = F_25 ( V_61 + sizeof( V_59 -> V_5 ) ) - sizeof( V_59 -> V_5 ) ;
V_41 = F_37 ( V_59 -> V_40 , V_34 ) ;
if ( V_41 ) {
F_23 ( V_61 ) ;
return V_41 ;
}
V_59 -> V_5 . V_62 = V_63 ;
V_59 -> V_5 . V_64 = V_32 * V_34 ;
V_59 -> V_5 . V_65 = V_43 ;
* V_55 = V_59 ;
* V_56 = V_61 ;
* V_57 = V_59 -> V_5 . V_64 + sizeof( struct V_66 ) ;
return 0 ;
}
T_5 int F_47 ( void )
{
int V_41 ;
if ( F_34 () ) {
F_48 ( L_1 ) ;
return - V_67 ;
}
if ( V_44 == V_38 ) {
V_41 = F_49 ( & V_68 ) ;
if ( V_41 )
return V_41 ;
}
if ( V_69 ) {
V_41 = F_39 () ;
if ( V_41 ) {
F_48 ( L_2
L_3 ) ;
F_50 ( V_70 ) ;
return V_41 ;
}
}
return 0 ;
}
void F_51 ( void )
{
F_50 ( V_70 ) ;
F_43 () ;
F_22 () ;
F_52 ( & V_68 ) ;
}
static int F_53 ( struct V_71 * V_72 , void * V_73 )
{
struct V_71 * V_74 ;
char V_75 [ V_76 ] ;
void * V_41 ;
snprintf ( V_75 , V_76 , L_4 , F_12 ( V_44 ,
V_73 ) ) ;
V_74 = F_54 ( V_72 , V_75 ) ;
V_41 = F_55 ( V_74 , L_5 ,
F_13 ( V_44 , V_73 ) -
F_14 ( V_44 , V_73 ) ) ;
if ( F_35 ( V_41 ) )
return F_36 ( V_41 ) ;
V_41 = F_55 ( V_74 , L_6 ,
F_14 ( V_44 , V_73 ) ) ;
if ( F_35 ( V_41 ) )
return F_36 ( V_41 ) ;
if ( V_44 == V_38 ) {
V_41 = F_55 ( V_74 , L_7 ,
F_15 ( V_44 ,
V_73 ) ) ;
if ( F_35 ( V_41 ) )
return F_36 ( V_41 ) ;
}
F_44 ( F_11 ( V_44 , V_73 ) , V_75 ) ;
V_41 = F_56 ( V_74 , L_8 , V_75 ) ;
return F_57 ( V_41 ) ;
}
static void * F_58 ( struct V_71 * V_77 , void * V_78 )
{
struct V_71 * V_72 ;
struct V_71 * V_79 ;
char V_80 [ V_15 + 1 ] ;
void * V_73 ;
int V_81 ;
F_7 ( V_44 , V_78 , V_80 ) ;
V_80 [ V_15 ] = 0 ;
V_79 = F_54 ( V_77 , V_80 ) ;
if ( F_35 ( V_79 ) )
return V_79 ;
V_72 = F_54 ( V_79 , L_9 ) ;
if ( F_35 ( V_72 ) )
return V_72 ;
V_73 = V_78 + F_5 ( V_44 ) ;
for ( V_81 = 0 ; V_81 < F_6 ( V_44 , V_78 ) ; V_81 ++ ) {
int V_41 ;
V_41 = F_53 ( V_72 , V_73 ) ;
if ( V_41 )
return F_29 ( V_41 ) ;
V_73 += F_10 ( V_44 ) ;
}
return V_73 ;
}
static int F_59 ( struct V_71 * V_72 , void * V_73 )
{
struct V_71 * V_74 ;
char V_75 [ V_76 ] ;
void * V_41 ;
snprintf ( V_75 , V_76 , L_10 , F_19 ( V_44 ,
V_73 ) ) ;
V_74 = F_54 ( V_72 , V_75 ) ;
if ( F_35 ( V_74 ) )
return F_36 ( V_74 ) ;
V_41 = F_55 ( V_74 , L_5 ,
F_20 ( V_44 , V_73 ) ) ;
if ( F_35 ( V_41 ) )
return F_36 ( V_41 ) ;
F_44 ( F_21 ( V_44 , V_73 ) , V_75 ) ;
V_41 = F_56 ( V_74 , L_8 , V_75 ) ;
return F_57 ( V_41 ) ;
}
static void * F_60 ( struct V_71 * V_82 , void * V_83 )
{
int V_81 ;
void * V_73 ;
struct V_71 * V_72 ;
V_72 = F_54 ( V_82 , L_9 ) ;
if ( F_35 ( V_72 ) )
return V_72 ;
V_73 = V_83 + F_16 ( V_44 ) ;
for ( V_81 = 0 ; V_81 < F_17 ( V_44 , V_83 ) ; V_81 ++ ) {
int V_41 ;
V_41 = F_59 ( V_72 , V_73 ) ;
if ( V_41 )
return F_29 ( V_41 ) ;
V_73 += F_18 ( V_44 ) ;
}
return V_73 ;
}
int F_61 ( struct V_71 * V_84 )
{
struct V_71 * V_77 , * V_85 ;
void * V_86 , * V_78 ;
int V_81 , V_41 ;
void * V_75 , * V_30 ;
V_75 = F_38 () ;
if ( F_35 ( V_75 ) )
return F_36 ( V_75 ) ;
V_77 = F_54 ( V_84 , L_11 ) ;
if ( F_35 ( V_77 ) ) {
V_41 = F_36 ( V_77 ) ;
goto V_87;
}
V_86 = (struct V_88 * ) V_75 ;
V_78 = V_86 + F_1 ( V_44 ) ;
for ( V_81 = 0 ; V_81 < F_2 ( V_44 , V_86 ) ; V_81 ++ ) {
V_78 = F_58 ( V_77 , V_78 ) ;
if ( F_35 ( V_78 ) ) {
V_41 = F_36 ( V_78 ) ;
goto V_87;
}
}
if ( F_3 ( V_44 , V_86 ) &
V_89 ) {
V_30 = F_60 ( V_84 , V_78 ) ;
if ( F_35 ( V_30 ) ) {
V_41 = F_36 ( V_30 ) ;
goto V_87;
}
}
V_85 = F_54 ( V_84 , L_12 ) ;
if ( F_35 ( V_85 ) ) {
V_41 = F_36 ( V_85 ) ;
goto V_87;
}
V_30 = F_56 ( V_85 , L_8 , L_13 ) ;
if ( F_35 ( V_30 ) ) {
V_41 = F_36 ( V_30 ) ;
goto V_87;
}
V_41 = 0 ;
V_87:
return V_41 ;
}
