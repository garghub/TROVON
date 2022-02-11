int F_1 ( struct V_1 T_1 * V_2 , int V_3 ,
int V_4 , T_2 V_5 )
{
T_3 V_6 ;
F_2 ( & V_2 -> V_7 , ( V_3 << 8 ) | V_4 ) ;
F_2 ( & V_2 -> V_8 , V_5 ) ;
V_6 = F_3 ( ! ( F_4 ( & V_2 -> V_9 ) & V_10 ) ,
V_11 , 0 ) ;
return V_6 ? 0 : - V_12 ;
}
int F_5 ( struct V_1 T_1 * V_2 ,
int V_3 , int V_4 )
{
T_2 V_5 ;
T_3 V_6 ;
F_2 ( & V_2 -> V_7 , ( V_3 << 8 ) | V_4 ) ;
F_2 ( & V_2 -> V_13 , 0 ) ;
F_2 ( & V_2 -> V_13 , V_14 ) ;
V_6 = F_3 ( ! ( F_4 ( & V_2 -> V_9 ) &
( V_15 | V_10 ) ) ,
V_11 , 0 ) ;
if ( ! V_6 )
return - V_12 ;
V_5 = F_4 ( & V_2 -> V_16 ) ;
return V_5 ;
}
static struct V_1 T_1 * F_6 ( struct V_17 * V_18 )
{
struct V_19 * V_20 = V_18 -> V_20 ;
return V_20 -> V_2 ;
}
int F_7 ( struct V_17 * V_18 , int V_3 , int V_4 , T_2 V_5 )
{
struct V_1 T_1 * V_2 = F_6 ( V_18 ) ;
return F_1 ( V_2 , V_3 , V_4 , V_5 ) ;
}
int F_8 ( struct V_17 * V_18 , int V_3 , int V_4 )
{
struct V_1 T_1 * V_2 = F_6 ( V_18 ) ;
return F_5 ( V_2 , V_3 , V_4 ) ;
}
static int F_9 ( struct V_17 * V_18 )
{
struct V_1 T_1 * V_2 = F_6 ( V_18 ) ;
T_3 V_6 ;
F_10 ( & V_18 -> V_21 ) ;
F_2 ( & V_2 -> V_22 , V_23 ) ;
F_2 ( & V_2 -> V_22 , V_24 ) ;
V_6 = F_3 ( ! ( F_4 ( & V_2 -> V_9 ) & V_10 ) ,
V_11 , 0 ) ;
F_11 ( & V_18 -> V_21 ) ;
if ( ! V_6 ) {
F_12 ( V_25 L_1 ,
V_18 -> V_26 ) ;
return - V_27 ;
}
return 0 ;
}
void F_13 ( char * V_26 , struct V_28 * V_29 )
{
const T_3 * V_30 ;
T_4 V_31 = V_32 ;
V_30 = F_14 ( V_29 , 0 , NULL , NULL ) ;
if ( V_30 )
V_31 = F_15 ( V_29 , V_30 ) ;
snprintf ( V_26 , V_33 , L_2 , V_29 -> V_26 ,
( unsigned long long ) V_31 ) ;
}
static T_3 T_1 * F_16 ( struct V_1 T_1 * V_2 , struct V_28 * V_29 )
{
#if F_17 ( V_34 ) || F_17 ( V_35 )
struct V_36 T_1 * V_37 ;
if( F_18 ( V_29 , L_3 ) ||
F_18 ( V_29 , L_4 ) ||
F_18 ( V_29 , L_5 ) ) {
V_37 = (struct V_36 T_1 * ) V_2 ;
return & V_37 -> V_38 ;
} else if ( F_18 ( V_29 , L_6 ) ||
F_18 ( V_29 , L_7 ) ) {
return F_19 ( V_29 , 1 ) ;
}
#endif
return NULL ;
}
static int F_20 ( T_4 V_39 , T_4 V_40 , T_3 * V_41 )
{
#if F_17 ( V_42 ) || F_17 ( V_43 )
struct V_28 * V_29 = NULL ;
int V_44 = 0 ;
F_21 (np, NULL, L_8 ) {
struct V_45 V_46 ;
V_44 = F_22 ( V_29 , 0 , & V_46 ) ;
if ( V_44 )
continue;
if ( ( V_39 >= V_46 . V_39 ) && ( V_40 <= V_46 . V_40 ) ) {
const T_3 * V_47 ;
V_47 = F_23 ( V_29 , L_9 , NULL ) ;
if ( ! V_47 ) {
V_47 = F_23 ( V_29 , L_10 , NULL ) ;
if ( ! V_47 )
continue;
}
* V_41 = * V_47 ;
return 0 ;
}
}
if ( V_44 )
return V_44 ;
else
return - V_48 ;
#else
return - V_49 ;
#endif
}
static int F_24 ( struct V_50 * V_51 )
{
struct V_28 * V_29 = V_51 -> V_52 . V_53 ;
struct V_28 * V_54 ;
struct V_19 * V_20 ;
struct V_1 T_1 * V_2 = NULL ;
void T_1 * V_55 ;
T_3 T_1 * V_38 ;
struct V_17 * V_56 ;
int V_57 = - 1 ;
const T_3 * V_58 ;
T_4 V_30 = 0 , V_59 = 0 ;
int V_44 ;
V_20 = F_25 ( sizeof( * V_20 ) , V_60 ) ;
if ( ! V_20 )
return - V_61 ;
V_56 = F_26 () ;
if ( ! V_56 ) {
V_44 = - V_61 ;
goto V_62;
}
V_56 -> V_26 = L_11 ,
V_56 -> V_63 = & F_8 ,
V_56 -> V_64 = & F_7 ,
V_56 -> V_65 = & F_9 ,
V_56 -> V_20 = V_20 ;
F_13 ( V_56 -> V_47 , V_29 ) ;
V_58 = F_14 ( V_29 , 0 , & V_59 , NULL ) ;
if ( ! V_58 ) {
V_44 = - V_48 ;
goto V_66;
}
V_30 = F_15 ( V_29 , V_58 ) ;
if ( V_30 == V_32 ) {
V_44 = - V_48 ;
goto V_66;
}
V_55 = F_27 ( V_30 , V_59 ) ;
if ( ! V_55 ) {
V_44 = - V_61 ;
goto V_66;
}
V_20 -> V_55 = V_55 ;
if ( F_18 ( V_29 , L_3 ) ||
F_18 ( V_29 , L_4 ) ||
F_18 ( V_29 , L_12 ) ||
F_18 ( V_29 , L_13 ) )
V_55 -= F_28 ( struct V_1 , V_22 ) ;
V_2 = V_55 ;
V_20 -> V_2 = V_2 ;
V_56 -> V_67 = F_29 ( V_68 , sizeof( int ) , V_60 ) ;
if ( NULL == V_56 -> V_67 ) {
V_44 = - V_61 ;
goto V_69;
}
V_56 -> V_70 = & V_51 -> V_52 ;
F_30 ( & V_51 -> V_52 , V_56 ) ;
if ( F_18 ( V_29 , L_3 ) ||
F_18 ( V_29 , L_4 ) ||
F_18 ( V_29 , L_6 ) ||
F_18 ( V_29 , L_7 ) ||
F_18 ( V_29 , L_5 ) ) {
V_38 = F_16 ( V_2 , V_29 ) ;
if ( ! V_38 ) {
V_44 = - V_48 ;
goto V_71;
}
} else if ( F_18 ( V_29 , L_12 ) ||
F_18 ( V_29 , L_13 ) ) {
T_3 V_47 ;
static T_3 V_72 ;
V_38 = & V_2 -> V_73 ;
if ( ( V_44 = F_20 ( V_30 , V_30 + V_59 , & V_47 ) ) )
goto V_71;
if ( ! V_72 ) {
V_72 = V_47 ;
F_31 ( V_47 - 1 ) ;
}
} else {
V_44 = - V_49 ;
goto V_71;
}
F_32 (np, tbi) {
if ( ! strncmp ( V_54 -> type , L_14 , 8 ) )
break;
}
if ( V_54 ) {
const T_3 * V_74 = F_23 ( V_54 , L_15 , NULL ) ;
if ( V_74 )
V_57 = * V_74 ;
if ( V_57 == - 1 ) {
V_44 = - V_27 ;
goto V_71;
} else {
F_2 ( V_38 , V_57 ) ;
}
}
V_44 = F_33 ( V_56 , V_29 ) ;
if ( V_44 ) {
F_12 ( V_25 L_16 ,
V_56 -> V_26 ) ;
goto V_71;
}
return 0 ;
V_71:
F_34 ( V_56 -> V_67 ) ;
V_69:
F_35 ( V_20 -> V_55 ) ;
V_66:
F_34 ( V_56 ) ;
V_62:
F_34 ( V_20 ) ;
return V_44 ;
}
static int F_36 ( struct V_50 * V_51 )
{
struct V_75 * V_75 = & V_51 -> V_52 ;
struct V_17 * V_18 = F_37 ( V_75 ) ;
struct V_19 * V_20 = V_18 -> V_20 ;
F_38 ( V_18 ) ;
F_30 ( V_75 , NULL ) ;
F_35 ( V_20 -> V_55 ) ;
V_18 -> V_20 = NULL ;
F_39 ( V_18 ) ;
F_34 ( V_20 ) ;
return 0 ;
}
