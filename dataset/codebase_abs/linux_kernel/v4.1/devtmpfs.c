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
V_31 = F_20 ( F_21 ( V_32 . V_3 ) , V_3 , V_18 ) ;
if ( ! V_31 )
F_21 ( V_3 ) -> V_35 = & V_17 ;
F_22 ( & V_32 , V_3 ) ;
return V_31 ;
}
static int F_23 ( const char * V_36 )
{
char * V_32 ;
char * V_37 ;
int V_31 = 0 ;
V_32 = F_24 ( V_36 , V_38 ) ;
if ( ! V_32 )
return - V_24 ;
V_37 = V_32 ;
for (; ; ) {
V_37 = strchr ( V_37 , '/' ) ;
if ( ! V_37 )
break;
V_37 [ 0 ] = '\0' ;
V_31 = F_16 ( V_32 , 0755 ) ;
if ( V_31 && V_31 != - V_39 )
break;
V_37 [ 0 ] = '/' ;
V_37 ++ ;
}
F_14 ( V_32 ) ;
return V_31 ;
}
static int F_25 ( const char * V_40 , T_2 V_18 , T_3 V_19 ,
T_4 V_21 , struct V_11 * V_12 )
{
struct V_3 * V_3 ;
struct V_32 V_32 ;
int V_31 ;
V_3 = F_17 ( V_33 , V_40 , & V_32 , 0 ) ;
if ( V_3 == F_26 ( - V_41 ) ) {
F_23 ( V_40 ) ;
V_3 = F_17 ( V_33 , V_40 , & V_32 , 0 ) ;
}
if ( F_18 ( V_3 ) )
return F_19 ( V_3 ) ;
V_31 = F_27 ( F_21 ( V_32 . V_3 ) , V_3 , V_18 , V_12 -> V_42 ) ;
if ( ! V_31 ) {
struct V_43 V_44 ;
V_44 . V_45 = V_18 ;
V_44 . V_46 = V_19 ;
V_44 . V_47 = V_21 ;
V_44 . V_48 = V_49 | V_50 | V_51 ;
F_28 ( & F_21 ( V_3 ) -> V_52 ) ;
F_29 ( V_3 , & V_44 , NULL ) ;
F_30 ( & F_21 ( V_3 ) -> V_52 ) ;
F_21 ( V_3 ) -> V_35 = & V_17 ;
}
F_22 ( & V_32 , V_3 ) ;
return V_31 ;
}
static int F_31 ( const char * V_23 )
{
struct V_32 V_53 ;
struct V_3 * V_3 ;
int V_31 ;
V_3 = F_32 ( V_23 , & V_53 ) ;
if ( F_18 ( V_3 ) )
return F_19 ( V_3 ) ;
if ( F_33 ( V_3 ) ) {
if ( F_21 ( V_3 ) -> V_35 == & V_17 )
V_31 = F_34 ( F_21 ( V_53 . V_3 ) , V_3 ) ;
else
V_31 = - V_54 ;
} else {
V_31 = - V_41 ;
}
F_35 ( V_3 ) ;
F_30 ( & F_21 ( V_53 . V_3 ) -> V_52 ) ;
F_36 ( & V_53 ) ;
return V_31 ;
}
static int F_37 ( const char * V_36 )
{
const char * V_32 ;
int V_31 = 0 ;
V_32 = F_24 ( V_36 , V_38 ) ;
if ( ! V_32 )
return - V_24 ;
for (; ; ) {
char * V_55 ;
V_55 = strrchr ( V_32 , '/' ) ;
if ( ! V_55 )
break;
V_55 [ 0 ] = '\0' ;
V_31 = F_31 ( V_32 ) ;
if ( V_31 )
break;
}
F_14 ( V_32 ) ;
return V_31 ;
}
static int F_38 ( struct V_11 * V_12 , struct V_56 * V_56 , struct V_57 * V_58 )
{
if ( V_56 -> V_35 != & V_17 )
return 0 ;
if ( F_6 ( V_12 ) ) {
if ( ! F_39 ( V_58 -> V_18 ) )
return 0 ;
} else {
if ( ! F_40 ( V_58 -> V_18 ) )
return 0 ;
}
if ( V_58 -> V_59 != V_12 -> V_42 )
return 0 ;
return 1 ;
}
static int F_41 ( const char * V_40 , struct V_11 * V_12 )
{
struct V_32 V_53 ;
struct V_3 * V_3 ;
int V_60 = 0 ;
int V_31 ;
V_3 = F_32 ( V_40 , & V_53 ) ;
if ( F_18 ( V_3 ) )
return F_19 ( V_3 ) ;
if ( F_33 ( V_3 ) ) {
struct V_57 V_58 ;
struct V_32 V_61 = { . V_62 = V_53 . V_62 , . V_3 = V_3 } ;
V_31 = F_42 ( & V_61 , & V_58 ) ;
if ( ! V_31 && F_38 ( V_12 , F_21 ( V_3 ) , & V_58 ) ) {
struct V_43 V_44 ;
V_44 . V_46 = V_20 ;
V_44 . V_47 = V_22 ;
V_44 . V_45 = V_58 . V_18 & ~ 0777 ;
V_44 . V_48 =
V_50 | V_51 | V_49 ;
F_28 ( & F_21 ( V_3 ) -> V_52 ) ;
F_29 ( V_3 , & V_44 , NULL ) ;
F_30 ( & F_21 ( V_3 ) -> V_52 ) ;
V_31 = F_43 ( F_21 ( V_53 . V_3 ) , V_3 , NULL ) ;
if ( ! V_31 || V_31 == - V_41 )
V_60 = 1 ;
}
} else {
V_31 = - V_41 ;
}
F_35 ( V_3 ) ;
F_30 ( & F_21 ( V_53 . V_3 ) -> V_52 ) ;
F_36 ( & V_53 ) ;
if ( V_60 && strchr ( V_40 , '/' ) )
F_37 ( V_40 ) ;
return V_31 ;
}
int F_44 ( const char * V_63 )
{
int V_31 ;
if ( ! V_2 )
return 0 ;
if ( ! V_17 )
return 0 ;
V_31 = F_45 ( L_1 , ( char * ) V_63 , L_1 , V_64 , NULL ) ;
if ( V_31 )
F_46 ( V_65 L_2 , V_31 ) ;
else
F_46 ( V_65 L_3 ) ;
return V_31 ;
}
static int F_47 ( const char * V_23 , T_2 V_18 , T_3 V_19 , T_4 V_21 ,
struct V_11 * V_12 )
{
if ( V_18 )
return F_25 ( V_23 , V_18 , V_19 , V_21 , V_12 ) ;
else
return F_41 ( V_23 , V_12 ) ;
}
static int F_48 ( void * V_61 )
{
char V_66 [] = L_4 ;
int * V_31 = V_61 ;
* V_31 = F_49 ( V_67 ) ;
if ( * V_31 )
goto V_68;
* V_31 = F_45 ( L_1 , L_5 , L_1 , V_64 , V_66 ) ;
if ( * V_31 )
goto V_68;
F_50 ( L_6 ) ;
F_51 ( L_7 ) ;
F_52 ( & V_69 ) ;
while ( 1 ) {
F_10 ( & V_28 ) ;
while ( V_30 ) {
struct V_16 * V_16 = V_30 ;
V_30 = NULL ;
F_11 ( & V_28 ) ;
while ( V_16 ) {
struct V_16 * V_29 = V_16 -> V_29 ;
V_16 -> V_31 = F_47 ( V_16 -> V_23 , V_16 -> V_18 ,
V_16 -> V_19 , V_16 -> V_21 , V_16 -> V_12 ) ;
F_52 ( & V_16 -> V_27 ) ;
V_16 = V_29 ;
}
F_10 ( & V_28 ) ;
}
F_53 ( V_70 ) ;
F_11 ( & V_28 ) ;
F_54 () ;
}
return 0 ;
V_68:
F_52 ( & V_69 ) ;
return * V_31 ;
}
int T_1 F_55 ( void )
{
int V_31 = F_56 ( & V_71 ) ;
if ( V_31 ) {
F_46 ( V_72 L_8
L_9 , V_31 ) ;
return V_31 ;
}
V_17 = F_57 ( F_48 , & V_31 , L_10 ) ;
if ( ! F_18 ( V_17 ) ) {
F_13 ( & V_69 ) ;
} else {
V_31 = F_19 ( V_17 ) ;
V_17 = NULL ;
}
if ( V_31 ) {
F_46 ( V_72 L_11 , V_31 ) ;
F_58 ( & V_71 ) ;
return V_31 ;
}
F_46 ( V_65 L_12 ) ;
return 0 ;
}
