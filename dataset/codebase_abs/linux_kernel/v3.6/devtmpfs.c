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
V_16 . V_19 = F_8 ( V_12 , & V_16 . V_18 , & V_15 ) ;
if ( ! V_16 . V_19 )
return - V_20 ;
if ( V_16 . V_18 == 0 )
V_16 . V_18 = 0600 ;
if ( F_6 ( V_12 ) )
V_16 . V_18 |= V_21 ;
else
V_16 . V_18 |= V_22 ;
V_16 . V_12 = V_12 ;
F_9 ( & V_16 . V_23 ) ;
F_10 ( & V_24 ) ;
V_16 . V_25 = V_26 ;
V_26 = & V_16 ;
F_11 ( & V_24 ) ;
F_12 ( V_17 ) ;
F_13 ( & V_16 . V_23 ) ;
F_14 ( V_15 ) ;
return V_16 . V_27 ;
}
int F_15 ( struct V_11 * V_12 )
{
const char * V_15 = NULL ;
struct V_16 V_16 ;
if ( ! V_17 )
return 0 ;
V_16 . V_19 = F_8 ( V_12 , NULL , & V_15 ) ;
if ( ! V_16 . V_19 )
return - V_20 ;
V_16 . V_18 = 0 ;
V_16 . V_12 = V_12 ;
F_9 ( & V_16 . V_23 ) ;
F_10 ( & V_24 ) ;
V_16 . V_25 = V_26 ;
V_26 = & V_16 ;
F_11 ( & V_24 ) ;
F_12 ( V_17 ) ;
F_13 ( & V_16 . V_23 ) ;
F_14 ( V_15 ) ;
return V_16 . V_27 ;
}
static int F_16 ( const char * V_19 , T_2 V_18 )
{
struct V_3 * V_3 ;
struct V_28 V_28 ;
int V_27 ;
V_3 = F_17 ( V_29 , V_19 , & V_28 , 1 ) ;
if ( F_18 ( V_3 ) )
return F_19 ( V_3 ) ;
V_27 = F_20 ( V_28 . V_3 -> V_30 , V_3 , V_18 ) ;
if ( ! V_27 )
V_3 -> V_30 -> V_31 = & V_17 ;
F_21 ( & V_28 , V_3 ) ;
return V_27 ;
}
static int F_22 ( const char * V_32 )
{
char * V_28 ;
char * V_33 ;
int V_27 = 0 ;
V_28 = F_23 ( V_32 , V_34 ) ;
if ( ! V_28 )
return - V_20 ;
V_33 = V_28 ;
for (; ; ) {
V_33 = strchr ( V_33 , '/' ) ;
if ( ! V_33 )
break;
V_33 [ 0 ] = '\0' ;
V_27 = F_16 ( V_28 , 0755 ) ;
if ( V_27 && V_27 != - V_35 )
break;
V_33 [ 0 ] = '/' ;
V_33 ++ ;
}
F_14 ( V_28 ) ;
return V_27 ;
}
static int F_24 ( const char * V_36 , T_2 V_18 , struct V_11 * V_12 )
{
struct V_3 * V_3 ;
struct V_28 V_28 ;
int V_27 ;
V_3 = F_17 ( V_29 , V_36 , & V_28 , 0 ) ;
if ( V_3 == F_25 ( - V_37 ) ) {
F_22 ( V_36 ) ;
V_3 = F_17 ( V_29 , V_36 , & V_28 , 0 ) ;
}
if ( F_18 ( V_3 ) )
return F_19 ( V_3 ) ;
V_27 = F_26 ( V_28 . V_3 -> V_30 ,
V_3 , V_18 , V_12 -> V_38 ) ;
if ( ! V_27 ) {
struct V_39 V_40 ;
V_40 . V_41 = V_18 ;
V_40 . V_42 = V_43 ;
F_27 ( & V_3 -> V_30 -> V_44 ) ;
F_28 ( V_3 , & V_40 ) ;
F_29 ( & V_3 -> V_30 -> V_44 ) ;
V_3 -> V_30 -> V_31 = & V_17 ;
}
F_21 ( & V_28 , V_3 ) ;
return V_27 ;
}
static int F_30 ( const char * V_19 )
{
struct V_28 V_45 ;
struct V_3 * V_3 ;
int V_27 ;
V_3 = F_31 ( V_19 , & V_45 ) ;
if ( F_18 ( V_3 ) )
return F_19 ( V_3 ) ;
if ( V_3 -> V_30 ) {
if ( V_3 -> V_30 -> V_31 == & V_17 )
V_27 = F_32 ( V_45 . V_3 -> V_30 , V_3 ) ;
else
V_27 = - V_46 ;
} else {
V_27 = - V_37 ;
}
F_33 ( V_3 ) ;
F_29 ( & V_45 . V_3 -> V_30 -> V_44 ) ;
F_34 ( & V_45 ) ;
return V_27 ;
}
static int F_35 ( const char * V_32 )
{
const char * V_28 ;
int V_27 = 0 ;
V_28 = F_23 ( V_32 , V_34 ) ;
if ( ! V_28 )
return - V_20 ;
for (; ; ) {
char * V_47 ;
V_47 = strrchr ( V_28 , '/' ) ;
if ( ! V_47 )
break;
V_47 [ 0 ] = '\0' ;
V_27 = F_30 ( V_28 ) ;
if ( V_27 )
break;
}
F_14 ( V_28 ) ;
return V_27 ;
}
static int F_36 ( struct V_11 * V_12 , struct V_48 * V_48 , struct V_49 * V_50 )
{
if ( V_48 -> V_31 != & V_17 )
return 0 ;
if ( F_6 ( V_12 ) ) {
if ( ! F_37 ( V_50 -> V_18 ) )
return 0 ;
} else {
if ( ! F_38 ( V_50 -> V_18 ) )
return 0 ;
}
if ( V_50 -> V_51 != V_12 -> V_38 )
return 0 ;
return 1 ;
}
static int F_39 ( const char * V_36 , struct V_11 * V_12 )
{
struct V_28 V_45 ;
struct V_3 * V_3 ;
int V_52 = 1 ;
int V_27 ;
V_3 = F_31 ( V_36 , & V_45 ) ;
if ( F_18 ( V_3 ) )
return F_19 ( V_3 ) ;
if ( V_3 -> V_30 ) {
struct V_49 V_50 ;
V_27 = F_40 ( V_45 . V_53 , V_3 , & V_50 ) ;
if ( ! V_27 && F_36 ( V_12 , V_3 -> V_30 , & V_50 ) ) {
struct V_39 V_40 ;
V_40 . V_54 = 0 ;
V_40 . V_55 = 0 ;
V_40 . V_41 = V_50 . V_18 & ~ 0777 ;
V_40 . V_42 =
V_56 | V_57 | V_43 ;
F_27 ( & V_3 -> V_30 -> V_44 ) ;
F_28 ( V_3 , & V_40 ) ;
F_29 ( & V_3 -> V_30 -> V_44 ) ;
V_27 = F_41 ( V_45 . V_3 -> V_30 , V_3 ) ;
if ( ! V_27 || V_27 == - V_37 )
V_52 = 1 ;
}
} else {
V_27 = - V_37 ;
}
F_33 ( V_3 ) ;
F_29 ( & V_45 . V_3 -> V_30 -> V_44 ) ;
F_34 ( & V_45 ) ;
if ( V_52 && strchr ( V_36 , '/' ) )
F_35 ( V_36 ) ;
return V_27 ;
}
int F_42 ( const char * V_58 )
{
int V_27 ;
if ( ! V_2 )
return 0 ;
if ( ! V_17 )
return 0 ;
V_27 = F_43 ( L_1 , ( char * ) V_58 , L_1 , V_59 , NULL ) ;
if ( V_27 )
F_44 ( V_60 L_2 , V_27 ) ;
else
F_44 ( V_60 L_3 ) ;
return V_27 ;
}
static int F_45 ( const char * V_19 , T_2 V_18 , struct V_11 * V_12 )
{
if ( V_18 )
return F_24 ( V_19 , V_18 , V_12 ) ;
else
return F_39 ( V_19 , V_12 ) ;
}
static int F_46 ( void * V_61 )
{
char V_62 [] = L_4 ;
int * V_27 = V_61 ;
* V_27 = F_47 ( V_63 ) ;
if ( * V_27 )
goto V_64;
* V_27 = F_43 ( L_1 , L_5 , L_1 , V_59 , V_62 ) ;
if ( * V_27 )
goto V_64;
F_48 ( L_6 ) ;
F_49 ( L_7 ) ;
F_50 ( & V_65 ) ;
while ( 1 ) {
F_10 ( & V_24 ) ;
while ( V_26 ) {
struct V_16 * V_16 = V_26 ;
V_26 = NULL ;
F_11 ( & V_24 ) ;
while ( V_16 ) {
struct V_16 * V_25 = V_16 -> V_25 ;
V_16 -> V_27 = F_45 ( V_16 -> V_19 , V_16 -> V_18 , V_16 -> V_12 ) ;
F_50 ( & V_16 -> V_23 ) ;
V_16 = V_25 ;
}
F_10 ( & V_24 ) ;
}
F_51 ( V_66 ) ;
F_11 ( & V_24 ) ;
F_52 () ;
}
return 0 ;
V_64:
F_50 ( & V_65 ) ;
return * V_27 ;
}
int T_1 F_53 ( void )
{
int V_27 = F_54 ( & V_67 ) ;
if ( V_27 ) {
F_44 ( V_68 L_8
L_9 , V_27 ) ;
return V_27 ;
}
V_17 = F_55 ( F_46 , & V_27 , L_10 ) ;
if ( ! F_18 ( V_17 ) ) {
F_13 ( & V_65 ) ;
} else {
V_27 = F_19 ( V_17 ) ;
V_17 = NULL ;
}
if ( V_27 ) {
F_44 ( V_68 L_11 , V_27 ) ;
F_56 ( & V_67 ) ;
return V_27 ;
}
F_44 ( V_60 L_12 ) ;
return 0 ;
}
