int F_1 ( struct V_1 T_1 * V_2 , int V_3 ,
int V_4 , T_2 V_5 )
{
F_2 ( & V_2 -> V_6 , ( V_3 << 8 ) | V_4 ) ;
F_2 ( & V_2 -> V_7 , V_5 ) ;
while ( F_3 ( & V_2 -> V_8 ) & V_9 )
F_4 () ;
return 0 ;
}
int F_5 ( struct V_1 T_1 * V_2 ,
int V_3 , int V_4 )
{
T_2 V_5 ;
F_2 ( & V_2 -> V_6 , ( V_3 << 8 ) | V_4 ) ;
F_2 ( & V_2 -> V_10 , 0 ) ;
F_2 ( & V_2 -> V_10 , V_11 ) ;
while ( F_3 ( & V_2 -> V_8 ) & ( V_12 | V_9 ) )
F_4 () ;
V_5 = F_3 ( & V_2 -> V_13 ) ;
return V_5 ;
}
static struct V_1 T_1 * F_6 ( struct V_14 * V_15 )
{
struct V_16 * V_17 = V_15 -> V_17 ;
return V_17 -> V_2 ;
}
int F_7 ( struct V_14 * V_15 , int V_3 , int V_4 , T_2 V_5 )
{
struct V_1 T_1 * V_2 = F_6 ( V_15 ) ;
return F_1 ( V_2 , V_3 , V_4 , V_5 ) ;
}
int F_8 ( struct V_14 * V_15 , int V_3 , int V_4 )
{
struct V_1 T_1 * V_2 = F_6 ( V_15 ) ;
return F_5 ( V_2 , V_3 , V_4 ) ;
}
static int F_9 ( struct V_14 * V_15 )
{
struct V_1 T_1 * V_2 = F_6 ( V_15 ) ;
int V_18 = V_19 ;
F_10 ( & V_15 -> V_20 ) ;
F_2 ( & V_2 -> V_21 , V_22 ) ;
F_2 ( & V_2 -> V_21 , V_23 ) ;
while ( ( F_3 ( & V_2 -> V_8 ) & V_9 ) && V_18 -- )
F_4 () ;
F_11 ( & V_15 -> V_20 ) ;
if ( V_18 < 0 ) {
F_12 ( V_24 L_1 ,
V_15 -> V_25 ) ;
return - V_26 ;
}
return 0 ;
}
void F_13 ( char * V_25 , struct V_27 * V_28 )
{
const T_3 * V_29 ;
T_4 V_30 = V_31 ;
V_29 = F_14 ( V_28 , 0 , NULL , NULL ) ;
if ( V_29 )
V_30 = F_15 ( V_28 , V_29 ) ;
snprintf ( V_25 , V_32 , L_2 , V_28 -> V_25 ,
( unsigned long long ) V_30 ) ;
}
static T_3 T_1 * F_16 ( struct V_1 T_1 * V_2 , struct V_27 * V_28 )
{
#if F_17 ( V_33 ) || F_17 ( V_34 )
struct V_35 T_1 * V_36 ;
if( F_18 ( V_28 , L_3 ) ||
F_18 ( V_28 , L_4 ) ||
F_18 ( V_28 , L_5 ) ) {
V_36 = (struct V_35 T_1 * ) V_2 ;
return & V_36 -> V_37 ;
} else if ( F_18 ( V_28 , L_6 ) ||
F_18 ( V_28 , L_7 ) ) {
return F_19 ( V_28 , 1 ) ;
}
#endif
return NULL ;
}
static int F_20 ( T_4 V_38 , T_4 V_39 , T_3 * V_40 )
{
#if F_17 ( V_41 ) || F_17 ( V_42 )
struct V_27 * V_28 = NULL ;
int V_43 = 0 ;
F_21 (np, NULL, L_8 ) {
struct V_44 V_45 ;
V_43 = F_22 ( V_28 , 0 , & V_45 ) ;
if ( V_43 )
continue;
if ( ( V_38 >= V_45 . V_38 ) && ( V_39 <= V_45 . V_39 ) ) {
const T_3 * V_46 ;
V_46 = F_23 ( V_28 , L_9 , NULL ) ;
if ( ! V_46 ) {
V_46 = F_23 ( V_28 , L_10 , NULL ) ;
if ( ! V_46 )
continue;
}
* V_40 = * V_46 ;
return 0 ;
}
}
if ( V_43 )
return V_43 ;
else
return - V_47 ;
#else
return - V_48 ;
#endif
}
static int F_24 ( struct V_49 * V_50 )
{
struct V_27 * V_28 = V_50 -> V_51 . V_52 ;
struct V_27 * V_53 ;
struct V_16 * V_17 ;
struct V_1 T_1 * V_2 = NULL ;
void T_1 * V_54 ;
T_3 T_1 * V_37 ;
struct V_14 * V_55 ;
int V_56 = - 1 ;
const T_3 * V_57 ;
T_4 V_29 = 0 , V_58 = 0 ;
int V_43 ;
V_17 = F_25 ( sizeof( * V_17 ) , V_59 ) ;
if ( ! V_17 )
return - V_60 ;
V_55 = F_26 () ;
if ( ! V_55 ) {
V_43 = - V_60 ;
goto V_61;
}
V_55 -> V_25 = L_11 ,
V_55 -> V_62 = & F_8 ,
V_55 -> V_63 = & F_7 ,
V_55 -> V_64 = & F_9 ,
V_55 -> V_17 = V_17 ;
F_13 ( V_55 -> V_46 , V_28 ) ;
V_57 = F_14 ( V_28 , 0 , & V_58 , NULL ) ;
if ( ! V_57 ) {
V_43 = - V_47 ;
goto V_65;
}
V_29 = F_15 ( V_28 , V_57 ) ;
if ( V_29 == V_31 ) {
V_43 = - V_47 ;
goto V_65;
}
V_54 = F_27 ( V_29 , V_58 ) ;
if ( ! V_54 ) {
V_43 = - V_60 ;
goto V_65;
}
V_17 -> V_54 = V_54 ;
if ( F_18 ( V_28 , L_3 ) ||
F_18 ( V_28 , L_4 ) ||
F_18 ( V_28 , L_12 ) ||
F_18 ( V_28 , L_13 ) )
V_54 -= F_28 ( struct V_1 , V_21 ) ;
V_2 = V_54 ;
V_17 -> V_2 = V_2 ;
V_55 -> V_66 = F_29 ( V_67 , sizeof( int ) , V_59 ) ;
if ( NULL == V_55 -> V_66 ) {
V_43 = - V_60 ;
goto V_68;
}
V_55 -> V_69 = & V_50 -> V_51 ;
F_30 ( & V_50 -> V_51 , V_55 ) ;
if ( F_18 ( V_28 , L_3 ) ||
F_18 ( V_28 , L_4 ) ||
F_18 ( V_28 , L_6 ) ||
F_18 ( V_28 , L_7 ) ||
F_18 ( V_28 , L_5 ) ) {
V_37 = F_16 ( V_2 , V_28 ) ;
if ( ! V_37 ) {
V_43 = - V_47 ;
goto V_70;
}
} else if ( F_18 ( V_28 , L_12 ) ||
F_18 ( V_28 , L_13 ) ) {
T_3 V_46 ;
static T_3 V_71 ;
V_37 = & V_2 -> V_72 ;
if ( ( V_43 = F_20 ( V_29 , V_29 + V_58 , & V_46 ) ) )
goto V_70;
if ( ! V_71 ) {
V_71 = V_46 ;
F_31 ( V_46 - 1 ) ;
}
} else {
V_43 = - V_48 ;
goto V_70;
}
F_32 (np, tbi) {
if ( ! strncmp ( V_53 -> type , L_14 , 8 ) )
break;
}
if ( V_53 ) {
const T_3 * V_73 = F_23 ( V_53 , L_15 , NULL ) ;
if ( V_73 )
V_56 = * V_73 ;
}
if ( V_56 == - 1 ) {
V_43 = - V_26 ;
goto V_70;
}
F_2 ( V_37 , V_56 ) ;
V_43 = F_33 ( V_55 , V_28 ) ;
if ( V_43 ) {
F_12 ( V_24 L_16 ,
V_55 -> V_25 ) ;
goto V_70;
}
return 0 ;
V_70:
F_34 ( V_55 -> V_66 ) ;
V_68:
F_35 ( V_17 -> V_54 ) ;
V_65:
F_34 ( V_55 ) ;
V_61:
F_34 ( V_17 ) ;
return V_43 ;
}
static int F_36 ( struct V_49 * V_50 )
{
struct V_74 * V_74 = & V_50 -> V_51 ;
struct V_14 * V_15 = F_37 ( V_74 ) ;
struct V_16 * V_17 = V_15 -> V_17 ;
F_38 ( V_15 ) ;
F_30 ( V_74 , NULL ) ;
F_35 ( V_17 -> V_54 ) ;
V_15 -> V_17 = NULL ;
F_39 ( V_15 ) ;
F_34 ( V_17 ) ;
return 0 ;
}
int T_5 F_40 ( void )
{
return F_41 ( & V_75 ) ;
}
void F_42 ( void )
{
F_43 ( & V_75 ) ;
}
