static int T_1 F_1 ( char * V_1 )
{
V_2 = F_2 ( V_1 , NULL , 0 ) ;
return 1 ;
}
static struct V_3 * F_3 ( struct V_4 * V_5 , int V_6 ,
const char * V_7 , void * V_8 )
{
#ifdef F_4
return F_5 ( V_5 , V_6 , V_8 , V_9 ) ;
#else
return F_5 ( V_5 , V_6 , V_8 , V_10 ) ;
#endif
}
static inline int F_6 ( struct V_11 * V_12 )
{
return V_12 -> V_13 == & V_14 ;
}
static inline int F_6 ( struct V_11 * V_12 ) { return 0 ; }
int F_7 ( struct V_11 * V_12 )
{
const char * V_15 = NULL ;
struct V_16 V_16 ;
if ( ! V_17 )
return 0 ;
V_16 . V_18 = 0 ;
V_16 . V_19 = V_20 ;
V_16 . V_21 = V_22 ;
V_16 . V_23 = F_8 ( V_12 , & V_16 . V_18 , & V_16 . V_19 , & V_16 . V_21 , & V_15 ) ;
if ( ! V_16 . V_23 )
return - V_24 ;
if ( V_16 . V_18 == 0 )
V_16 . V_18 = 0600 ;
if ( F_6 ( V_12 ) )
V_16 . V_18 |= V_25 ;
else
V_16 . V_18 |= V_26 ;
V_16 . V_12 = V_12 ;
F_9 ( & V_16 . V_27 ) ;
F_10 ( & V_28 ) ;
V_16 . V_29 = V_30 ;
V_30 = & V_16 ;
F_11 ( & V_28 ) ;
F_12 ( V_17 ) ;
F_13 ( & V_16 . V_27 ) ;
F_14 ( V_15 ) ;
return V_16 . V_31 ;
}
int F_15 ( struct V_11 * V_12 )
{
const char * V_15 = NULL ;
struct V_16 V_16 ;
if ( ! V_17 )
return 0 ;
V_16 . V_23 = F_8 ( V_12 , NULL , NULL , NULL , & V_15 ) ;
if ( ! V_16 . V_23 )
return - V_24 ;
V_16 . V_18 = 0 ;
V_16 . V_12 = V_12 ;
F_9 ( & V_16 . V_27 ) ;
F_10 ( & V_28 ) ;
V_16 . V_29 = V_30 ;
V_30 = & V_16 ;
F_11 ( & V_28 ) ;
F_12 ( V_17 ) ;
F_13 ( & V_16 . V_27 ) ;
F_14 ( V_15 ) ;
return V_16 . V_31 ;
}
static int F_16 ( const char * V_23 , T_2 V_18 )
{
struct V_3 * V_3 ;
struct V_32 V_32 ;
int V_31 ;
V_3 = F_17 ( V_33 , V_23 , & V_32 , V_34 ) ;
if ( F_18 ( V_3 ) )
return F_19 ( V_3 ) ;
V_31 = F_20 ( V_32 . V_3 -> V_35 , V_3 , V_18 ) ;
if ( ! V_31 )
V_3 -> V_35 -> V_36 = & V_17 ;
F_21 ( & V_32 , V_3 ) ;
return V_31 ;
}
static int F_22 ( const char * V_37 )
{
char * V_32 ;
char * V_38 ;
int V_31 = 0 ;
V_32 = F_23 ( V_37 , V_39 ) ;
if ( ! V_32 )
return - V_24 ;
V_38 = V_32 ;
for (; ; ) {
V_38 = strchr ( V_38 , '/' ) ;
if ( ! V_38 )
break;
V_38 [ 0 ] = '\0' ;
V_31 = F_16 ( V_32 , 0755 ) ;
if ( V_31 && V_31 != - V_40 )
break;
V_38 [ 0 ] = '/' ;
V_38 ++ ;
}
F_14 ( V_32 ) ;
return V_31 ;
}
static int F_24 ( const char * V_41 , T_2 V_18 , T_3 V_19 ,
T_4 V_21 , struct V_11 * V_12 )
{
struct V_3 * V_3 ;
struct V_32 V_32 ;
int V_31 ;
V_3 = F_17 ( V_33 , V_41 , & V_32 , 0 ) ;
if ( V_3 == F_25 ( - V_42 ) ) {
F_22 ( V_41 ) ;
V_3 = F_17 ( V_33 , V_41 , & V_32 , 0 ) ;
}
if ( F_18 ( V_3 ) )
return F_19 ( V_3 ) ;
V_31 = F_26 ( V_32 . V_3 -> V_35 , V_3 , V_18 , V_12 -> V_43 ) ;
if ( ! V_31 ) {
struct V_44 V_45 ;
V_45 . V_46 = V_18 ;
V_45 . V_47 = V_19 ;
V_45 . V_48 = V_21 ;
V_45 . V_49 = V_50 | V_51 | V_52 ;
F_27 ( & V_3 -> V_35 -> V_53 ) ;
F_28 ( V_3 , & V_45 , NULL ) ;
F_29 ( & V_3 -> V_35 -> V_53 ) ;
V_3 -> V_35 -> V_36 = & V_17 ;
}
F_21 ( & V_32 , V_3 ) ;
return V_31 ;
}
static int F_30 ( const char * V_23 )
{
struct V_32 V_54 ;
struct V_3 * V_3 ;
int V_31 ;
V_3 = F_31 ( V_23 , & V_54 ) ;
if ( F_18 ( V_3 ) )
return F_19 ( V_3 ) ;
if ( V_3 -> V_35 ) {
if ( V_3 -> V_35 -> V_36 == & V_17 )
V_31 = F_32 ( V_54 . V_3 -> V_35 , V_3 ) ;
else
V_31 = - V_55 ;
} else {
V_31 = - V_42 ;
}
F_33 ( V_3 ) ;
F_29 ( & V_54 . V_3 -> V_35 -> V_53 ) ;
F_34 ( & V_54 ) ;
return V_31 ;
}
static int F_35 ( const char * V_37 )
{
const char * V_32 ;
int V_31 = 0 ;
V_32 = F_23 ( V_37 , V_39 ) ;
if ( ! V_32 )
return - V_24 ;
for (; ; ) {
char * V_56 ;
V_56 = strrchr ( V_32 , '/' ) ;
if ( ! V_56 )
break;
V_56 [ 0 ] = '\0' ;
V_31 = F_30 ( V_32 ) ;
if ( V_31 )
break;
}
F_14 ( V_32 ) ;
return V_31 ;
}
static int F_36 ( struct V_11 * V_12 , struct V_57 * V_57 , struct V_58 * V_59 )
{
if ( V_57 -> V_36 != & V_17 )
return 0 ;
if ( F_6 ( V_12 ) ) {
if ( ! F_37 ( V_59 -> V_18 ) )
return 0 ;
} else {
if ( ! F_38 ( V_59 -> V_18 ) )
return 0 ;
}
if ( V_59 -> V_60 != V_12 -> V_43 )
return 0 ;
return 1 ;
}
static int F_39 ( const char * V_41 , struct V_11 * V_12 )
{
struct V_32 V_54 ;
struct V_3 * V_3 ;
int V_61 = 0 ;
int V_31 ;
V_3 = F_31 ( V_41 , & V_54 ) ;
if ( F_18 ( V_3 ) )
return F_19 ( V_3 ) ;
if ( V_3 -> V_35 ) {
struct V_58 V_59 ;
struct V_32 V_62 = { . V_63 = V_54 . V_63 , . V_3 = V_3 } ;
V_31 = F_40 ( & V_62 , & V_59 ) ;
if ( ! V_31 && F_36 ( V_12 , V_3 -> V_35 , & V_59 ) ) {
struct V_44 V_45 ;
V_45 . V_47 = V_20 ;
V_45 . V_48 = V_22 ;
V_45 . V_46 = V_59 . V_18 & ~ 0777 ;
V_45 . V_49 =
V_51 | V_52 | V_50 ;
F_27 ( & V_3 -> V_35 -> V_53 ) ;
F_28 ( V_3 , & V_45 , NULL ) ;
F_29 ( & V_3 -> V_35 -> V_53 ) ;
V_31 = F_41 ( V_54 . V_3 -> V_35 , V_3 , NULL ) ;
if ( ! V_31 || V_31 == - V_42 )
V_61 = 1 ;
}
} else {
V_31 = - V_42 ;
}
F_33 ( V_3 ) ;
F_29 ( & V_54 . V_3 -> V_35 -> V_53 ) ;
F_34 ( & V_54 ) ;
if ( V_61 && strchr ( V_41 , '/' ) )
F_35 ( V_41 ) ;
return V_31 ;
}
int F_42 ( const char * V_64 )
{
int V_31 ;
if ( ! V_2 )
return 0 ;
if ( ! V_17 )
return 0 ;
V_31 = F_43 ( L_1 , ( char * ) V_64 , L_1 , V_65 , NULL ) ;
if ( V_31 )
F_44 ( V_66 L_2 , V_31 ) ;
else
F_44 ( V_66 L_3 ) ;
return V_31 ;
}
static int F_45 ( const char * V_23 , T_2 V_18 , T_3 V_19 , T_4 V_21 ,
struct V_11 * V_12 )
{
if ( V_18 )
return F_24 ( V_23 , V_18 , V_19 , V_21 , V_12 ) ;
else
return F_39 ( V_23 , V_12 ) ;
}
static int F_46 ( void * V_62 )
{
char V_67 [] = L_4 ;
int * V_31 = V_62 ;
* V_31 = F_47 ( V_68 ) ;
if ( * V_31 )
goto V_69;
* V_31 = F_43 ( L_1 , L_5 , L_1 , V_65 , V_67 ) ;
if ( * V_31 )
goto V_69;
F_48 ( L_6 ) ;
F_49 ( L_7 ) ;
F_50 ( & V_70 ) ;
while ( 1 ) {
F_10 ( & V_28 ) ;
while ( V_30 ) {
struct V_16 * V_16 = V_30 ;
V_30 = NULL ;
F_11 ( & V_28 ) ;
while ( V_16 ) {
struct V_16 * V_29 = V_16 -> V_29 ;
V_16 -> V_31 = F_45 ( V_16 -> V_23 , V_16 -> V_18 ,
V_16 -> V_19 , V_16 -> V_21 , V_16 -> V_12 ) ;
F_50 ( & V_16 -> V_27 ) ;
V_16 = V_29 ;
}
F_10 ( & V_28 ) ;
}
F_51 ( V_71 ) ;
F_11 ( & V_28 ) ;
F_52 () ;
}
return 0 ;
V_69:
F_50 ( & V_70 ) ;
return * V_31 ;
}
int T_1 F_53 ( void )
{
int V_31 = F_54 ( & V_72 ) ;
if ( V_31 ) {
F_44 ( V_73 L_8
L_9 , V_31 ) ;
return V_31 ;
}
V_17 = F_55 ( F_46 , & V_31 , L_10 ) ;
if ( ! F_18 ( V_17 ) ) {
F_13 ( & V_70 ) ;
} else {
V_31 = F_19 ( V_17 ) ;
V_17 = NULL ;
}
if ( V_31 ) {
F_44 ( V_73 L_11 , V_31 ) ;
F_56 ( & V_72 ) ;
return V_31 ;
}
F_44 ( V_66 L_12 ) ;
return 0 ;
}
