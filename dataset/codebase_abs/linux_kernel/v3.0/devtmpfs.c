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
static int F_7 ( const char * V_15 , T_2 V_16 )
{
struct V_17 V_18 ;
struct V_3 * V_3 ;
int V_19 ;
V_19 = F_8 ( V_20 -> V_21 , V_20 ,
V_15 , V_22 , & V_18 ) ;
if ( V_19 )
return V_19 ;
V_3 = F_9 ( & V_18 , 1 ) ;
if ( ! F_10 ( V_3 ) ) {
V_19 = F_11 ( V_18 . V_23 . V_3 -> V_24 , V_3 , V_16 ) ;
if ( ! V_19 )
V_3 -> V_24 -> V_25 = & V_20 ;
F_12 ( V_3 ) ;
} else {
V_19 = F_13 ( V_3 ) ;
}
F_14 ( & V_18 . V_23 . V_3 -> V_24 -> V_26 ) ;
F_15 ( & V_18 . V_23 ) ;
return V_19 ;
}
static int F_16 ( const char * V_27 )
{
int V_19 ;
F_17 ( & V_28 ) ;
V_19 = F_7 ( V_27 , 0755 ) ;
if ( V_19 == - V_29 ) {
char * V_23 ;
char * V_30 ;
V_23 = F_18 ( V_27 , V_31 ) ;
if ( ! V_23 ) {
V_19 = - V_32 ;
goto V_33;
}
V_30 = V_23 ;
for (; ; ) {
V_30 = strchr ( V_30 , '/' ) ;
if ( ! V_30 )
break;
V_30 [ 0 ] = '\0' ;
V_19 = F_7 ( V_23 , 0755 ) ;
if ( V_19 && V_19 != - V_34 )
break;
V_30 [ 0 ] = '/' ;
V_30 ++ ;
}
F_19 ( V_23 ) ;
}
V_33:
F_14 ( & V_28 ) ;
return V_19 ;
}
int F_20 ( struct V_11 * V_12 )
{
const char * V_35 = NULL ;
const char * V_36 ;
const struct V_37 * V_38 ;
T_2 V_16 = 0 ;
struct V_17 V_18 ;
struct V_3 * V_3 ;
int V_19 ;
if ( ! V_20 )
return 0 ;
V_36 = F_21 ( V_12 , & V_16 , & V_35 ) ;
if ( ! V_36 )
return - V_32 ;
if ( V_16 == 0 )
V_16 = 0600 ;
if ( F_6 ( V_12 ) )
V_16 |= V_39 ;
else
V_16 |= V_40 ;
V_38 = F_22 ( & V_41 ) ;
V_19 = F_8 ( V_20 -> V_21 , V_20 ,
V_36 , V_22 , & V_18 ) ;
if ( V_19 == - V_29 ) {
F_16 ( V_36 ) ;
V_19 = F_8 ( V_20 -> V_21 , V_20 ,
V_36 , V_22 , & V_18 ) ;
}
if ( V_19 )
goto V_33;
V_3 = F_9 ( & V_18 , 0 ) ;
if ( ! F_10 ( V_3 ) ) {
V_19 = F_23 ( V_18 . V_23 . V_3 -> V_24 ,
V_3 , V_16 , V_12 -> V_42 ) ;
if ( ! V_19 ) {
struct V_43 V_44 ;
V_44 . V_45 = V_16 ;
V_44 . V_46 = V_47 ;
F_17 ( & V_3 -> V_24 -> V_26 ) ;
F_24 ( V_3 , & V_44 ) ;
F_14 ( & V_3 -> V_24 -> V_26 ) ;
V_3 -> V_24 -> V_25 = & V_20 ;
}
F_12 ( V_3 ) ;
} else {
V_19 = F_13 ( V_3 ) ;
}
F_14 ( & V_18 . V_23 . V_3 -> V_24 -> V_26 ) ;
F_15 ( & V_18 . V_23 ) ;
V_33:
F_19 ( V_35 ) ;
F_25 ( V_38 ) ;
return V_19 ;
}
static int F_26 ( const char * V_15 )
{
struct V_17 V_18 ;
struct V_3 * V_3 ;
int V_19 ;
V_19 = F_8 ( V_20 -> V_21 , V_20 ,
V_15 , V_22 , & V_18 ) ;
if ( V_19 )
return V_19 ;
F_27 ( & V_18 . V_23 . V_3 -> V_24 -> V_26 , V_48 ) ;
V_3 = F_28 ( V_18 . V_49 . V_15 , V_18 . V_23 . V_3 , V_18 . V_49 . V_50 ) ;
if ( ! F_10 ( V_3 ) ) {
if ( V_3 -> V_24 ) {
if ( V_3 -> V_24 -> V_25 == & V_20 )
V_19 = F_29 ( V_18 . V_23 . V_3 -> V_24 ,
V_3 ) ;
else
V_19 = - V_51 ;
} else {
V_19 = - V_29 ;
}
F_12 ( V_3 ) ;
} else {
V_19 = F_13 ( V_3 ) ;
}
F_14 ( & V_18 . V_23 . V_3 -> V_24 -> V_26 ) ;
F_15 ( & V_18 . V_23 ) ;
return V_19 ;
}
static int F_30 ( const char * V_27 )
{
const char * V_23 ;
int V_19 = 0 ;
V_23 = F_18 ( V_27 , V_31 ) ;
if ( ! V_23 )
return - V_32 ;
F_17 ( & V_28 ) ;
for (; ; ) {
char * V_52 ;
V_52 = strrchr ( V_23 , '/' ) ;
if ( ! V_52 )
break;
V_52 [ 0 ] = '\0' ;
V_19 = F_26 ( V_23 ) ;
if ( V_19 )
break;
}
F_14 ( & V_28 ) ;
F_19 ( V_23 ) ;
return V_19 ;
}
static int F_31 ( struct V_11 * V_12 , struct V_53 * V_53 , struct V_54 * V_55 )
{
if ( V_53 -> V_25 != & V_20 )
return 0 ;
if ( F_6 ( V_12 ) ) {
if ( ! F_32 ( V_55 -> V_16 ) )
return 0 ;
} else {
if ( ! F_33 ( V_55 -> V_16 ) )
return 0 ;
}
if ( V_55 -> V_56 != V_12 -> V_42 )
return 0 ;
return 1 ;
}
int F_34 ( struct V_11 * V_12 )
{
const char * V_35 = NULL ;
const char * V_36 ;
const struct V_37 * V_38 ;
struct V_17 V_18 ;
struct V_3 * V_3 ;
struct V_54 V_55 ;
int V_57 = 1 ;
int V_19 ;
if ( ! V_20 )
return 0 ;
V_36 = F_21 ( V_12 , NULL , & V_35 ) ;
if ( ! V_36 )
return - V_32 ;
V_38 = F_22 ( & V_41 ) ;
V_19 = F_8 ( V_20 -> V_21 , V_20 ,
V_36 , V_22 , & V_18 ) ;
if ( V_19 )
goto V_33;
F_27 ( & V_18 . V_23 . V_3 -> V_24 -> V_26 , V_48 ) ;
V_3 = F_28 ( V_18 . V_49 . V_15 , V_18 . V_23 . V_3 , V_18 . V_49 . V_50 ) ;
if ( ! F_10 ( V_3 ) ) {
if ( V_3 -> V_24 ) {
V_19 = F_35 ( V_18 . V_23 . V_58 , V_3 , & V_55 ) ;
if ( ! V_19 && F_31 ( V_12 , V_3 -> V_24 , & V_55 ) ) {
struct V_43 V_44 ;
V_44 . V_59 = 0 ;
V_44 . V_60 = 0 ;
V_44 . V_45 = V_55 . V_16 & ~ 0777 ;
V_44 . V_46 =
V_61 | V_62 | V_47 ;
F_17 ( & V_3 -> V_24 -> V_26 ) ;
F_24 ( V_3 , & V_44 ) ;
F_14 ( & V_3 -> V_24 -> V_26 ) ;
V_19 = F_36 ( V_18 . V_23 . V_3 -> V_24 ,
V_3 ) ;
if ( ! V_19 || V_19 == - V_29 )
V_57 = 1 ;
}
} else {
V_19 = - V_29 ;
}
F_12 ( V_3 ) ;
} else {
V_19 = F_13 ( V_3 ) ;
}
F_14 ( & V_18 . V_23 . V_3 -> V_24 -> V_26 ) ;
F_15 ( & V_18 . V_23 ) ;
if ( V_57 && strchr ( V_36 , '/' ) )
F_30 ( V_36 ) ;
V_33:
F_19 ( V_35 ) ;
F_25 ( V_38 ) ;
return V_19 ;
}
int F_37 ( const char * V_63 )
{
int V_19 ;
if ( ! V_2 )
return 0 ;
if ( ! V_20 )
return 0 ;
V_19 = F_38 ( L_1 , ( char * ) V_63 , L_1 , V_64 , NULL ) ;
if ( V_19 )
F_39 ( V_65 L_2 , V_19 ) ;
else
F_39 ( V_65 L_3 ) ;
return V_19 ;
}
int T_1 F_40 ( void )
{
int V_19 ;
struct V_66 * V_58 ;
char V_67 [] = L_4 ;
V_19 = F_41 ( & V_68 ) ;
if ( V_19 ) {
F_39 ( V_69 L_5
L_6 , V_19 ) ;
return V_19 ;
}
V_58 = F_42 ( & V_68 , V_67 ) ;
if ( F_10 ( V_58 ) ) {
V_19 = F_13 ( V_58 ) ;
F_39 ( V_69 L_7 , V_19 ) ;
F_43 ( & V_68 ) ;
return V_19 ;
}
V_20 = V_58 ;
F_39 ( V_65 L_8 ) ;
return 0 ;
}
