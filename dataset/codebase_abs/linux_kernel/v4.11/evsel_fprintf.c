static int F_1 ( T_1 * V_1 , bool * V_2 , const char * V_3 , ... )
{
T_2 args ;
int V_4 = 0 ;
if ( ! * V_2 ) {
V_4 += fprintf ( V_1 , L_1 ) ;
} else {
V_4 += fprintf ( V_1 , L_2 ) ;
* V_2 = false ;
}
va_start ( args , V_3 ) ;
V_4 += vfprintf ( V_1 , V_3 , args ) ;
va_end ( args ) ;
return V_4 ;
}
static int F_2 ( T_1 * V_1 , const char * V_5 , const char * V_6 , void * V_7 )
{
return F_1 ( V_1 , ( bool * ) V_7 , L_3 , V_5 , V_6 ) ;
}
int F_3 ( struct V_8 * V_9 ,
struct V_10 * V_11 , T_1 * V_1 )
{
bool V_2 = true ;
int V_12 = 0 ;
if ( V_11 -> V_13 ) {
struct V_8 * V_14 ;
if ( ! F_4 ( V_9 ) )
return 0 ;
if ( V_9 -> V_15 > 1 )
V_12 += fprintf ( V_1 , L_4 , V_9 -> V_16 ? : L_5 ) ;
V_12 += fprintf ( V_1 , L_6 , F_5 ( V_9 ) ) ;
F_6 (pos, evsel)
V_12 += fprintf ( V_1 , L_7 , F_5 ( V_14 ) ) ;
if ( V_9 -> V_15 > 1 )
V_12 += fprintf ( V_1 , L_8 ) ;
goto V_17;
}
V_12 += fprintf ( V_1 , L_6 , F_5 ( V_9 ) ) ;
if ( V_11 -> V_18 ) {
V_12 += F_7 ( V_1 , & V_9 -> V_19 ,
F_2 , & V_2 ) ;
} else if ( V_11 -> V_20 ) {
const char * V_21 = L_9 ;
if ( ! V_9 -> V_19 . V_20 )
V_21 = L_10 ;
V_12 += F_1 ( V_1 , & V_2 , L_11 V_22 ,
V_21 , ( V_23 ) V_9 -> V_19 . V_24 ) ;
}
if ( V_11 -> V_25 ) {
struct V_26 * V_27 ;
if ( V_9 -> V_19 . type != V_28 ) {
V_12 += F_1 ( V_1 , & V_2 , L_12 ) ;
goto V_17;
}
V_27 = V_9 -> V_29 -> V_30 . V_31 ;
if ( V_27 == NULL ) {
V_12 += F_1 ( V_1 , & V_2 , L_13 ) ;
goto V_17;
}
V_12 += F_1 ( V_1 , & V_2 , L_14 , V_27 -> V_5 ) ;
V_27 = V_27 -> V_32 ;
while ( V_27 ) {
V_12 += F_1 ( V_1 , & V_2 , L_6 , V_27 -> V_5 ) ;
V_27 = V_27 -> V_32 ;
}
}
V_17:
fputc ( '\n' , V_1 ) ;
return ++ V_12 ;
}
int F_8 ( struct V_33 * V_34 , int V_35 ,
unsigned int V_36 , struct V_37 * V_38 ,
T_1 * V_1 )
{
int V_12 = 0 ;
struct V_39 * V_40 ;
int V_41 = V_36 & V_42 ;
int V_43 = V_36 & V_44 ;
int V_45 = V_36 & V_46 ;
int V_47 = V_36 & V_48 ;
int V_49 = V_36 & V_50 ;
int V_51 = V_36 & V_52 ;
int V_53 = V_36 & V_54 ;
int V_55 = V_36 & V_56 ;
int V_57 = V_36 & V_58 ;
char V_59 = V_49 ? ' ' : '\t' ;
bool V_2 = true ;
if ( V_34 -> V_60 ) {
struct V_61 V_62 ;
F_9 ( V_38 ) ;
while ( 1 ) {
V_23 V_63 = 0 ;
V_40 = F_10 ( V_38 ) ;
if ( ! V_40 )
break;
if ( V_40 -> V_64 && V_40 -> V_64 -> V_65 && V_57 )
goto V_32;
V_12 += fprintf ( V_1 , L_15 , V_35 , V_35 , L_16 ) ;
if ( V_55 && ! V_2 )
V_12 += fprintf ( V_1 , L_17 ) ;
if ( V_41 )
V_12 += fprintf ( V_1 , L_18 V_66 , V_59 , V_40 -> V_67 ) ;
if ( V_40 -> V_68 )
V_63 = V_40 -> V_68 -> V_69 ( V_40 -> V_68 , V_40 -> V_67 ) ;
if ( V_43 ) {
V_12 += fprintf ( V_1 , L_16 ) ;
V_62 . V_63 = V_63 ;
V_62 . V_68 = V_40 -> V_68 ;
if ( V_47 ) {
V_12 += F_11 ( V_40 -> V_64 , & V_62 ,
V_53 ,
true , V_1 ) ;
} else {
V_12 += F_12 ( V_40 -> V_64 , & V_62 ,
V_53 , V_1 ) ;
}
}
if ( V_45 ) {
V_12 += fprintf ( V_1 , L_19 ) ;
V_12 += F_13 ( V_40 -> V_68 , V_1 ) ;
V_12 += fprintf ( V_1 , L_20 ) ;
}
if ( V_51 )
V_12 += F_14 ( V_40 -> V_68 , V_63 , L_21 , V_1 ) ;
if ( ! V_49 )
V_12 += fprintf ( V_1 , L_22 ) ;
if ( V_70 . V_71 &&
V_40 -> V_64 &&
F_15 ( V_70 . V_71 ,
V_40 -> V_64 -> V_5 ) ) {
break;
}
V_2 = false ;
V_32:
F_16 ( V_38 ) ;
}
}
return V_12 ;
}
int F_17 ( struct V_33 * V_34 , struct V_61 * V_72 ,
int V_35 , unsigned int V_36 ,
struct V_37 * V_38 , T_1 * V_1 )
{
int V_12 = 0 ;
int V_41 = V_36 & V_42 ;
int V_43 = V_36 & V_44 ;
int V_45 = V_36 & V_46 ;
int V_47 = V_36 & V_48 ;
int V_51 = V_36 & V_52 ;
int V_53 = V_36 & V_54 ;
if ( V_38 != NULL ) {
V_12 += F_8 ( V_34 , V_35 ,
V_36 , V_38 , V_1 ) ;
} else {
V_12 += fprintf ( V_1 , L_15 , V_35 , V_35 , L_16 ) ;
if ( V_41 )
V_12 += fprintf ( V_1 , L_23 V_66 , V_34 -> V_67 ) ;
if ( V_43 ) {
V_12 += fprintf ( V_1 , L_16 ) ;
if ( V_47 ) {
V_12 += F_11 ( V_72 -> V_64 , V_72 ,
V_53 ,
true , V_1 ) ;
} else {
V_12 += F_12 ( V_72 -> V_64 , V_72 ,
V_53 , V_1 ) ;
}
}
if ( V_45 ) {
V_12 += fprintf ( V_1 , L_19 ) ;
V_12 += F_13 ( V_72 -> V_68 , V_1 ) ;
V_12 += fprintf ( V_1 , L_20 ) ;
}
if ( V_51 )
V_12 += F_14 ( V_72 -> V_68 , V_72 -> V_63 , L_21 , V_1 ) ;
}
return V_12 ;
}
