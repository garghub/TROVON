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
F_21 ( V_3 ) ;
F_22 ( & V_28 . V_3 -> V_30 -> V_32 ) ;
F_23 ( & V_28 ) ;
return V_27 ;
}
static int F_24 ( const char * V_33 )
{
char * V_28 ;
char * V_34 ;
int V_27 = 0 ;
V_28 = F_25 ( V_33 , V_35 ) ;
if ( ! V_28 )
return - V_20 ;
V_34 = V_28 ;
for (; ; ) {
V_34 = strchr ( V_34 , '/' ) ;
if ( ! V_34 )
break;
V_34 [ 0 ] = '\0' ;
V_27 = F_16 ( V_28 , 0755 ) ;
if ( V_27 && V_27 != - V_36 )
break;
V_34 [ 0 ] = '/' ;
V_34 ++ ;
}
F_14 ( V_28 ) ;
return V_27 ;
}
static int F_26 ( const char * V_37 , T_2 V_18 , struct V_11 * V_12 )
{
struct V_3 * V_3 ;
struct V_28 V_28 ;
int V_27 ;
V_3 = F_17 ( V_29 , V_37 , & V_28 , 0 ) ;
if ( V_3 == F_27 ( - V_38 ) ) {
F_24 ( V_37 ) ;
V_3 = F_17 ( V_29 , V_37 , & V_28 , 0 ) ;
}
if ( F_18 ( V_3 ) )
return F_19 ( V_3 ) ;
V_27 = F_28 ( V_28 . V_3 -> V_30 ,
V_3 , V_18 , V_12 -> V_39 ) ;
if ( ! V_27 ) {
struct V_40 V_41 ;
V_41 . V_42 = V_18 ;
V_41 . V_43 = V_44 ;
F_29 ( & V_3 -> V_30 -> V_32 ) ;
F_30 ( V_3 , & V_41 ) ;
F_22 ( & V_3 -> V_30 -> V_32 ) ;
V_3 -> V_30 -> V_31 = & V_17 ;
}
F_21 ( V_3 ) ;
F_22 ( & V_28 . V_3 -> V_30 -> V_32 ) ;
F_23 ( & V_28 ) ;
return V_27 ;
}
static int F_31 ( const char * V_19 )
{
struct V_45 V_46 ;
struct V_3 * V_3 ;
int V_27 ;
V_27 = F_32 ( V_19 , & V_46 ) ;
if ( V_27 )
return V_27 ;
F_33 ( & V_46 . V_28 . V_3 -> V_30 -> V_32 , V_47 ) ;
V_3 = F_34 ( V_46 . V_48 . V_19 , V_46 . V_28 . V_3 , V_46 . V_48 . V_49 ) ;
if ( ! F_18 ( V_3 ) ) {
if ( V_3 -> V_30 ) {
if ( V_3 -> V_30 -> V_31 == & V_17 )
V_27 = F_35 ( V_46 . V_28 . V_3 -> V_30 ,
V_3 ) ;
else
V_27 = - V_50 ;
} else {
V_27 = - V_38 ;
}
F_21 ( V_3 ) ;
} else {
V_27 = F_19 ( V_3 ) ;
}
F_22 ( & V_46 . V_28 . V_3 -> V_30 -> V_32 ) ;
F_23 ( & V_46 . V_28 ) ;
return V_27 ;
}
static int F_36 ( const char * V_33 )
{
const char * V_28 ;
int V_27 = 0 ;
V_28 = F_25 ( V_33 , V_35 ) ;
if ( ! V_28 )
return - V_20 ;
for (; ; ) {
char * V_51 ;
V_51 = strrchr ( V_28 , '/' ) ;
if ( ! V_51 )
break;
V_51 [ 0 ] = '\0' ;
V_27 = F_31 ( V_28 ) ;
if ( V_27 )
break;
}
F_14 ( V_28 ) ;
return V_27 ;
}
static int F_37 ( struct V_11 * V_12 , struct V_52 * V_52 , struct V_53 * V_54 )
{
if ( V_52 -> V_31 != & V_17 )
return 0 ;
if ( F_6 ( V_12 ) ) {
if ( ! F_38 ( V_54 -> V_18 ) )
return 0 ;
} else {
if ( ! F_39 ( V_54 -> V_18 ) )
return 0 ;
}
if ( V_54 -> V_55 != V_12 -> V_39 )
return 0 ;
return 1 ;
}
static int F_40 ( const char * V_37 , struct V_11 * V_12 )
{
struct V_45 V_46 ;
struct V_3 * V_3 ;
struct V_53 V_54 ;
int V_56 = 1 ;
int V_27 ;
V_27 = F_32 ( V_37 , & V_46 ) ;
if ( V_27 )
return V_27 ;
F_33 ( & V_46 . V_28 . V_3 -> V_30 -> V_32 , V_47 ) ;
V_3 = F_34 ( V_46 . V_48 . V_19 , V_46 . V_28 . V_3 , V_46 . V_48 . V_49 ) ;
if ( ! F_18 ( V_3 ) ) {
if ( V_3 -> V_30 ) {
V_27 = F_41 ( V_46 . V_28 . V_57 , V_3 , & V_54 ) ;
if ( ! V_27 && F_37 ( V_12 , V_3 -> V_30 , & V_54 ) ) {
struct V_40 V_41 ;
V_41 . V_58 = 0 ;
V_41 . V_59 = 0 ;
V_41 . V_42 = V_54 . V_18 & ~ 0777 ;
V_41 . V_43 =
V_60 | V_61 | V_44 ;
F_29 ( & V_3 -> V_30 -> V_32 ) ;
F_30 ( V_3 , & V_41 ) ;
F_22 ( & V_3 -> V_30 -> V_32 ) ;
V_27 = F_42 ( V_46 . V_28 . V_3 -> V_30 ,
V_3 ) ;
if ( ! V_27 || V_27 == - V_38 )
V_56 = 1 ;
}
} else {
V_27 = - V_38 ;
}
F_21 ( V_3 ) ;
} else {
V_27 = F_19 ( V_3 ) ;
}
F_22 ( & V_46 . V_28 . V_3 -> V_30 -> V_32 ) ;
F_23 ( & V_46 . V_28 ) ;
if ( V_56 && strchr ( V_37 , '/' ) )
F_36 ( V_37 ) ;
return V_27 ;
}
int F_43 ( const char * V_62 )
{
int V_27 ;
if ( ! V_2 )
return 0 ;
if ( ! V_17 )
return 0 ;
V_27 = F_44 ( L_1 , ( char * ) V_62 , L_1 , V_63 , NULL ) ;
if ( V_27 )
F_45 ( V_64 L_2 , V_27 ) ;
else
F_45 ( V_64 L_3 ) ;
return V_27 ;
}
static int F_46 ( const char * V_19 , T_2 V_18 , struct V_11 * V_12 )
{
if ( V_18 )
return F_26 ( V_19 , V_18 , V_12 ) ;
else
return F_40 ( V_19 , V_12 ) ;
}
static int F_47 ( void * V_65 )
{
char V_66 [] = L_4 ;
int * V_27 = V_65 ;
* V_27 = F_48 ( V_67 ) ;
if ( * V_27 )
goto V_68;
* V_27 = F_44 ( L_1 , L_5 , L_1 , V_63 , V_66 ) ;
if ( * V_27 )
goto V_68;
F_49 ( L_6 ) ;
F_50 ( L_7 ) ;
F_51 ( & V_69 ) ;
while ( 1 ) {
F_10 ( & V_24 ) ;
while ( V_26 ) {
struct V_16 * V_16 = V_26 ;
V_26 = NULL ;
F_11 ( & V_24 ) ;
while ( V_16 ) {
struct V_16 * V_25 = V_16 -> V_25 ;
V_16 -> V_27 = F_46 ( V_16 -> V_19 , V_16 -> V_18 , V_16 -> V_12 ) ;
F_51 ( & V_16 -> V_23 ) ;
V_16 = V_25 ;
}
F_10 ( & V_24 ) ;
}
F_52 ( V_70 ) ;
F_11 ( & V_24 ) ;
F_53 () ;
}
return 0 ;
V_68:
F_51 ( & V_69 ) ;
return * V_27 ;
}
int T_1 F_54 ( void )
{
int V_27 = F_55 ( & V_71 ) ;
if ( V_27 ) {
F_45 ( V_72 L_8
L_9 , V_27 ) ;
return V_27 ;
}
V_17 = F_56 ( F_47 , & V_27 , L_10 ) ;
if ( ! F_18 ( V_17 ) ) {
F_13 ( & V_69 ) ;
} else {
V_27 = F_19 ( V_17 ) ;
V_17 = NULL ;
}
if ( V_27 ) {
F_45 ( V_72 L_11 , V_27 ) ;
F_57 ( & V_71 ) ;
return V_27 ;
}
F_45 ( V_64 L_12 ) ;
return 0 ;
}
