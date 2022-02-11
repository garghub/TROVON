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
static int F_16 ( struct V_14 * V_33 )
{
int V_34 ;
for ( V_34 = V_35 ; V_34 > 0 ; V_34 -- ) {
T_3 V_36 ;
if ( F_17 ( V_33 , V_34 , & V_36 ) )
return - 1 ;
if ( V_36 == 0xffffffff )
break;
}
return V_34 ;
}
static T_3 T_1 * F_18 ( struct V_1 T_1 * V_2 , struct V_27 * V_28 )
{
struct V_37 T_1 * V_38 ;
if( F_19 ( V_28 , L_3 ) ||
F_19 ( V_28 , L_4 ) ||
F_19 ( V_28 , L_5 ) ) {
V_38 = (struct V_37 T_1 * ) V_2 ;
return & V_38 -> V_39 ;
} else if ( F_19 ( V_28 , L_6 ) ||
F_19 ( V_28 , L_7 ) ) {
return F_20 ( V_28 , 1 ) ;
} else
return NULL ;
}
static int F_21 ( T_4 V_40 , T_4 V_41 , T_3 * V_42 )
{
struct V_27 * V_28 = NULL ;
int V_43 = 0 ;
F_22 (np, NULL, L_8 ) {
struct V_44 V_45 ;
V_43 = F_23 ( V_28 , 0 , & V_45 ) ;
if ( V_43 )
continue;
if ( ( V_40 >= V_45 . V_40 ) && ( V_41 <= V_45 . V_41 ) ) {
const T_3 * V_46 ;
V_46 = F_24 ( V_28 , L_9 , NULL ) ;
if ( ! V_46 ) {
V_46 = F_24 ( V_28 , L_10 , NULL ) ;
if ( ! V_46 )
continue;
}
* V_42 = * V_46 ;
return 0 ;
}
}
if ( V_43 )
return V_43 ;
else
return - V_47 ;
}
static int F_25 ( struct V_48 * V_49 )
{
struct V_27 * V_28 = V_49 -> V_50 . V_51 ;
struct V_27 * V_52 ;
struct V_16 * V_17 ;
struct V_1 T_1 * V_2 = NULL ;
void T_1 * V_53 ;
T_3 T_1 * V_39 ;
struct V_14 * V_33 ;
int V_54 = - 1 ;
const T_3 * V_55 ;
T_4 V_29 = 0 , V_56 = 0 ;
int V_43 ;
V_17 = F_26 ( sizeof( * V_17 ) , V_57 ) ;
if ( ! V_17 )
return - V_58 ;
V_33 = F_27 () ;
if ( ! V_33 ) {
V_43 = - V_58 ;
goto V_59;
}
V_33 -> V_25 = L_11 ,
V_33 -> V_60 = & F_8 ,
V_33 -> V_61 = & F_7 ,
V_33 -> V_62 = & F_9 ,
V_33 -> V_17 = V_17 ;
F_13 ( V_33 -> V_46 , V_28 ) ;
V_55 = F_14 ( V_28 , 0 , & V_56 , NULL ) ;
if ( ! V_55 ) {
V_43 = - V_47 ;
goto V_63;
}
V_29 = F_15 ( V_28 , V_55 ) ;
if ( V_29 == V_31 ) {
V_43 = - V_47 ;
goto V_63;
}
V_53 = F_28 ( V_29 , V_56 ) ;
if ( ! V_53 ) {
V_43 = - V_58 ;
goto V_63;
}
V_17 -> V_53 = V_53 ;
if ( F_19 ( V_28 , L_3 ) ||
F_19 ( V_28 , L_4 ) ||
F_19 ( V_28 , L_12 ) ||
F_19 ( V_28 , L_13 ) )
V_53 -= F_29 ( struct V_1 , V_21 ) ;
V_2 = V_53 ;
V_17 -> V_2 = V_2 ;
V_33 -> V_64 = F_30 ( V_35 , sizeof( int ) , V_57 ) ;
if ( NULL == V_33 -> V_64 ) {
V_43 = - V_58 ;
goto V_65;
}
V_33 -> V_66 = & V_49 -> V_50 ;
F_31 ( & V_49 -> V_50 , V_33 ) ;
if ( F_19 ( V_28 , L_3 ) ||
F_19 ( V_28 , L_4 ) ||
F_19 ( V_28 , L_6 ) ||
F_19 ( V_28 , L_7 ) ||
F_19 ( V_28 , L_5 ) ) {
#if F_32 ( V_67 ) || F_32 ( V_68 )
V_39 = F_18 ( V_2 , V_28 ) ;
if ( ! V_39 ) {
V_43 = - V_47 ;
goto V_69;
}
#else
V_43 = - V_70 ;
goto V_69;
#endif
} else if ( F_19 ( V_28 , L_12 ) ||
F_19 ( V_28 , L_13 ) ) {
#if F_32 ( V_71 ) || F_32 ( V_72 )
T_3 V_46 ;
static T_3 V_73 ;
V_39 = & V_2 -> V_74 ;
if ( ( V_43 = F_21 ( V_29 , V_29 + V_56 , & V_46 ) ) )
goto V_69;
if ( ! V_73 ) {
V_73 = V_46 ;
F_33 ( V_46 - 1 ) ;
}
#else
V_43 = - V_70 ;
goto V_69;
#endif
} else {
V_43 = - V_70 ;
goto V_69;
}
F_34 (np, tbi) {
if ( ! strncmp ( V_52 -> type , L_14 , 8 ) )
break;
}
if ( V_52 ) {
const T_3 * V_75 = F_24 ( V_52 , L_15 , NULL ) ;
if ( V_75 )
V_54 = * V_75 ;
}
if ( V_54 == - 1 ) {
F_2 ( V_39 , 0 ) ;
V_54 = F_16 ( V_33 ) ;
}
if ( V_54 == 0 ) {
V_43 = - V_26 ;
goto V_69;
}
F_2 ( V_39 , V_54 ) ;
V_43 = F_35 ( V_33 , V_28 ) ;
if ( V_43 ) {
F_12 ( V_24 L_16 ,
V_33 -> V_25 ) ;
goto V_69;
}
return 0 ;
V_69:
F_36 ( V_33 -> V_64 ) ;
V_65:
F_37 ( V_17 -> V_53 ) ;
V_63:
F_36 ( V_33 ) ;
V_59:
F_36 ( V_17 ) ;
return V_43 ;
}
static int F_38 ( struct V_48 * V_49 )
{
struct V_76 * V_76 = & V_49 -> V_50 ;
struct V_14 * V_15 = F_39 ( V_76 ) ;
struct V_16 * V_17 = V_15 -> V_17 ;
F_40 ( V_15 ) ;
F_31 ( V_76 , NULL ) ;
F_37 ( V_17 -> V_53 ) ;
V_15 -> V_17 = NULL ;
F_41 ( V_15 ) ;
F_36 ( V_17 ) ;
return 0 ;
}
int T_5 F_42 ( void )
{
return F_43 ( & V_77 ) ;
}
void F_44 ( void )
{
F_45 ( & V_77 ) ;
}
