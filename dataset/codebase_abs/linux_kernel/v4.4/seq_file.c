static void F_1 ( struct V_1 * V_2 )
{
V_2 -> V_3 = V_2 -> V_4 ;
}
static void * F_2 ( unsigned long V_4 )
{
void * V_5 ;
T_1 V_6 = V_7 ;
if ( V_4 > V_8 )
V_6 |= V_9 | V_10 ;
V_5 = F_3 ( V_4 , V_6 ) ;
if ( ! V_5 && V_4 > V_8 )
V_5 = F_4 ( V_4 ) ;
return V_5 ;
}
int F_5 ( struct V_11 * V_11 , const struct V_12 * V_13 )
{
struct V_1 * V_14 ;
F_6 ( V_11 -> V_15 ) ;
V_14 = F_7 ( sizeof( * V_14 ) , V_7 ) ;
if ( ! V_14 )
return - V_16 ;
V_11 -> V_15 = V_14 ;
F_8 ( & V_14 -> V_17 ) ;
V_14 -> V_13 = V_13 ;
#ifdef F_9
V_14 -> V_18 = V_11 -> V_19 -> V_18 ;
#endif
V_11 -> V_20 = 0 ;
V_11 -> V_21 &= ~ V_22 ;
return 0 ;
}
static int F_10 ( struct V_1 * V_2 , T_2 V_23 )
{
T_2 V_24 = 0 , V_25 ;
int error = 0 ;
void * V_14 ;
V_2 -> V_26 = 0 ;
V_25 = 0 ;
V_2 -> V_3 = V_2 -> V_27 = 0 ;
if ( ! V_23 ) {
V_2 -> V_25 = V_25 ;
return 0 ;
}
if ( ! V_2 -> V_5 ) {
V_2 -> V_5 = F_2 ( V_2 -> V_4 = V_8 ) ;
if ( ! V_2 -> V_5 )
return - V_16 ;
}
V_14 = V_2 -> V_13 -> V_28 ( V_2 , & V_25 ) ;
while ( V_14 ) {
error = F_11 ( V_14 ) ;
if ( F_12 ( V_14 ) )
break;
error = V_2 -> V_13 -> V_29 ( V_2 , V_14 ) ;
if ( error < 0 )
break;
if ( F_13 ( error ) ) {
error = 0 ;
V_2 -> V_3 = 0 ;
}
if ( F_14 ( V_2 ) )
goto V_30;
if ( V_24 + V_2 -> V_3 > V_23 ) {
V_2 -> V_27 = V_23 - V_24 ;
V_2 -> V_3 -= V_2 -> V_27 ;
V_2 -> V_25 = V_25 ;
break;
}
V_24 += V_2 -> V_3 ;
V_2 -> V_3 = 0 ;
if ( V_24 == V_23 ) {
V_25 ++ ;
V_2 -> V_25 = V_25 ;
break;
}
V_14 = V_2 -> V_13 -> V_31 ( V_2 , V_14 , & V_25 ) ;
}
V_2 -> V_13 -> V_32 ( V_2 , V_14 ) ;
V_2 -> V_25 = V_25 ;
return error ;
V_30:
V_2 -> V_13 -> V_32 ( V_2 , V_14 ) ;
F_15 ( V_2 -> V_5 ) ;
V_2 -> V_3 = 0 ;
V_2 -> V_5 = F_2 ( V_2 -> V_4 <<= 1 ) ;
return ! V_2 -> V_5 ? - V_16 : - V_33 ;
}
T_3 F_16 ( struct V_11 * V_11 , char T_4 * V_5 , T_5 V_4 , T_2 * V_34 )
{
struct V_1 * V_2 = V_11 -> V_15 ;
T_5 V_35 = 0 ;
T_2 V_24 ;
T_5 V_36 ;
void * V_14 ;
int V_37 = 0 ;
F_17 ( & V_2 -> V_17 ) ;
V_2 -> V_26 = V_11 -> V_20 ;
if ( F_13 ( * V_34 != V_2 -> V_38 ) ) {
while ( ( V_37 = F_10 ( V_2 , * V_34 ) ) == - V_33 )
;
if ( V_37 ) {
V_2 -> V_38 = 0 ;
V_2 -> V_26 = 0 ;
V_2 -> V_25 = 0 ;
V_2 -> V_3 = 0 ;
goto V_39;
} else {
V_2 -> V_38 = * V_34 ;
}
}
if ( ! V_2 -> V_5 ) {
V_2 -> V_5 = F_2 ( V_2 -> V_4 = V_8 ) ;
if ( ! V_2 -> V_5 )
goto V_40;
}
if ( V_2 -> V_3 ) {
V_36 = F_18 ( V_2 -> V_3 , V_4 ) ;
V_37 = F_19 ( V_5 , V_2 -> V_5 + V_2 -> V_27 , V_36 ) ;
if ( V_37 )
goto V_41;
V_2 -> V_3 -= V_36 ;
V_2 -> V_27 += V_36 ;
V_4 -= V_36 ;
V_5 += V_36 ;
V_35 += V_36 ;
if ( ! V_2 -> V_3 )
V_2 -> V_25 ++ ;
if ( ! V_4 )
goto V_39;
}
V_24 = V_2 -> V_25 ;
V_14 = V_2 -> V_13 -> V_28 ( V_2 , & V_24 ) ;
while ( 1 ) {
V_37 = F_11 ( V_14 ) ;
if ( ! V_14 || F_12 ( V_14 ) )
break;
V_37 = V_2 -> V_13 -> V_29 ( V_2 , V_14 ) ;
if ( V_37 < 0 )
break;
if ( F_13 ( V_37 ) )
V_2 -> V_3 = 0 ;
if ( F_13 ( ! V_2 -> V_3 ) ) {
V_14 = V_2 -> V_13 -> V_31 ( V_2 , V_14 , & V_24 ) ;
V_2 -> V_25 = V_24 ;
continue;
}
if ( V_2 -> V_3 < V_2 -> V_4 )
goto V_42;
V_2 -> V_13 -> V_32 ( V_2 , V_14 ) ;
F_15 ( V_2 -> V_5 ) ;
V_2 -> V_3 = 0 ;
V_2 -> V_5 = F_2 ( V_2 -> V_4 <<= 1 ) ;
if ( ! V_2 -> V_5 )
goto V_40;
V_2 -> V_26 = 0 ;
V_24 = V_2 -> V_25 ;
V_14 = V_2 -> V_13 -> V_28 ( V_2 , & V_24 ) ;
}
V_2 -> V_13 -> V_32 ( V_2 , V_14 ) ;
V_2 -> V_3 = 0 ;
goto V_39;
V_42:
while ( V_2 -> V_3 < V_4 ) {
T_5 V_43 = V_2 -> V_3 ;
T_2 V_31 = V_24 ;
V_14 = V_2 -> V_13 -> V_31 ( V_2 , V_14 , & V_31 ) ;
if ( ! V_14 || F_12 ( V_14 ) ) {
V_37 = F_11 ( V_14 ) ;
break;
}
V_37 = V_2 -> V_13 -> V_29 ( V_2 , V_14 ) ;
if ( F_14 ( V_2 ) || V_37 ) {
V_2 -> V_3 = V_43 ;
if ( F_20 ( V_37 <= 0 ) )
break;
}
V_24 = V_31 ;
}
V_2 -> V_13 -> V_32 ( V_2 , V_14 ) ;
V_36 = F_18 ( V_2 -> V_3 , V_4 ) ;
V_37 = F_19 ( V_5 , V_2 -> V_5 , V_36 ) ;
if ( V_37 )
goto V_41;
V_35 += V_36 ;
V_2 -> V_3 -= V_36 ;
if ( V_2 -> V_3 )
V_2 -> V_27 = V_36 ;
else
V_24 ++ ;
V_2 -> V_25 = V_24 ;
V_39:
if ( ! V_35 )
V_35 = V_37 ;
else {
* V_34 += V_35 ;
V_2 -> V_38 += V_35 ;
}
V_11 -> V_20 = V_2 -> V_26 ;
F_21 ( & V_2 -> V_17 ) ;
return V_35 ;
V_40:
V_37 = - V_16 ;
goto V_39;
V_41:
V_37 = - V_44 ;
goto V_39;
}
T_2 F_22 ( struct V_11 * V_11 , T_2 V_23 , int V_45 )
{
struct V_1 * V_2 = V_11 -> V_15 ;
T_2 V_46 = - V_47 ;
F_17 ( & V_2 -> V_17 ) ;
V_2 -> V_26 = V_11 -> V_20 ;
switch ( V_45 ) {
case V_48 :
V_23 += V_11 -> V_49 ;
case V_50 :
if ( V_23 < 0 )
break;
V_46 = V_23 ;
if ( V_23 != V_2 -> V_38 ) {
while ( ( V_46 = F_10 ( V_2 , V_23 ) ) == - V_33 )
;
if ( V_46 ) {
V_11 -> V_49 = 0 ;
V_2 -> V_38 = 0 ;
V_2 -> V_26 = 0 ;
V_2 -> V_25 = 0 ;
V_2 -> V_3 = 0 ;
} else {
V_2 -> V_38 = V_23 ;
V_46 = V_11 -> V_49 = V_23 ;
}
} else {
V_11 -> V_49 = V_23 ;
}
}
V_11 -> V_20 = V_2 -> V_26 ;
F_21 ( & V_2 -> V_17 ) ;
return V_46 ;
}
int F_23 ( struct V_51 * V_51 , struct V_11 * V_11 )
{
struct V_1 * V_2 = V_11 -> V_15 ;
F_15 ( V_2 -> V_5 ) ;
F_24 ( V_2 ) ;
return 0 ;
}
void F_25 ( struct V_1 * V_2 , const char * V_52 , const char * V_53 )
{
char * V_5 ;
T_5 V_4 = F_26 ( V_2 , & V_5 ) ;
int V_54 ;
V_54 = F_27 ( V_52 , V_5 , V_4 , V_55 , V_53 ) ;
F_28 ( V_2 , V_54 < V_4 ? V_54 : - 1 ) ;
}
void F_29 ( struct V_1 * V_2 , const char * V_56 , T_6 args )
{
int V_57 ;
if ( V_2 -> V_3 < V_2 -> V_4 ) {
V_57 = vsnprintf ( V_2 -> V_5 + V_2 -> V_3 , V_2 -> V_4 - V_2 -> V_3 , V_56 , args ) ;
if ( V_2 -> V_3 + V_57 < V_2 -> V_4 ) {
V_2 -> V_3 += V_57 ;
return;
}
}
F_1 ( V_2 ) ;
}
void F_30 ( struct V_1 * V_2 , const char * V_56 , ... )
{
T_6 args ;
va_start ( args , V_56 ) ;
F_29 ( V_2 , V_56 , args ) ;
va_end ( args ) ;
}
char * F_31 ( char * V_52 , const char * V_14 , const char * V_53 )
{
while ( V_52 <= V_14 ) {
char V_58 = * V_14 ++ ;
if ( ! V_58 ) {
return V_52 ;
} else if ( ! strchr ( V_53 , V_58 ) ) {
* V_52 ++ = V_58 ;
} else if ( V_52 + 4 > V_14 ) {
break;
} else {
* V_52 ++ = '\\' ;
* V_52 ++ = '0' + ( ( V_58 & 0300 ) >> 6 ) ;
* V_52 ++ = '0' + ( ( V_58 & 070 ) >> 3 ) ;
* V_52 ++ = '0' + ( V_58 & 07 ) ;
}
}
return NULL ;
}
int F_32 ( struct V_1 * V_2 , const struct V_59 * V_59 , const char * V_53 )
{
char * V_5 ;
T_5 V_4 = F_26 ( V_2 , & V_5 ) ;
int V_60 = - 1 ;
if ( V_4 ) {
char * V_14 = F_33 ( V_59 , V_5 , V_4 ) ;
if ( ! F_12 ( V_14 ) ) {
char * V_61 = F_31 ( V_5 , V_14 , V_53 ) ;
if ( V_61 )
V_60 = V_61 - V_5 ;
}
}
F_28 ( V_2 , V_60 ) ;
return V_60 ;
}
int F_34 ( struct V_1 * V_2 , struct V_11 * V_11 , const char * V_53 )
{
return F_32 ( V_2 , & V_11 -> V_62 , V_53 ) ;
}
int F_35 ( struct V_1 * V_2 , const struct V_59 * V_59 ,
const struct V_59 * V_63 , const char * V_53 )
{
char * V_5 ;
T_5 V_4 = F_26 ( V_2 , & V_5 ) ;
int V_60 = - V_64 ;
if ( V_4 ) {
char * V_14 ;
V_14 = F_36 ( V_59 , V_63 , V_5 , V_4 ) ;
if ( ! V_14 )
return V_65 ;
V_60 = F_11 ( V_14 ) ;
if ( ! F_12 ( V_14 ) ) {
char * V_61 = F_31 ( V_5 , V_14 , V_53 ) ;
if ( V_61 )
V_60 = V_61 - V_5 ;
else
V_60 = - V_64 ;
}
}
F_28 ( V_2 , V_60 ) ;
return V_60 < 0 && V_60 != - V_64 ? V_60 : 0 ;
}
int F_37 ( struct V_1 * V_2 , struct V_66 * V_66 , const char * V_53 )
{
char * V_5 ;
T_5 V_4 = F_26 ( V_2 , & V_5 ) ;
int V_60 = - 1 ;
if ( V_4 ) {
char * V_14 = F_38 ( V_66 , V_5 , V_4 ) ;
if ( ! F_12 ( V_14 ) ) {
char * V_61 = F_31 ( V_5 , V_14 , V_53 ) ;
if ( V_61 )
V_60 = V_61 - V_5 ;
}
}
F_28 ( V_2 , V_60 ) ;
return V_60 ;
}
static void * F_39 ( struct V_1 * V_14 , T_2 * V_24 )
{
return NULL + ( * V_24 == 0 ) ;
}
static void * F_40 ( struct V_1 * V_14 , void * V_67 , T_2 * V_24 )
{
++ * V_24 ;
return NULL ;
}
static void F_41 ( struct V_1 * V_14 , void * V_67 )
{
}
int F_42 ( struct V_11 * V_11 , int (* V_29)( struct V_1 * , void * ) ,
void * V_68 )
{
struct V_12 * V_13 = F_3 ( sizeof( * V_13 ) , V_7 ) ;
int V_60 = - V_16 ;
if ( V_13 ) {
V_13 -> V_28 = F_39 ;
V_13 -> V_31 = F_40 ;
V_13 -> V_32 = F_41 ;
V_13 -> V_29 = V_29 ;
V_60 = F_5 ( V_11 , V_13 ) ;
if ( ! V_60 )
( (struct V_1 * ) V_11 -> V_15 ) -> V_69 = V_68 ;
else
F_24 ( V_13 ) ;
}
return V_60 ;
}
int F_43 ( struct V_11 * V_11 , int (* V_29)( struct V_1 * , void * ) ,
void * V_68 , T_5 V_4 )
{
char * V_5 = F_2 ( V_4 ) ;
int V_54 ;
if ( ! V_5 )
return - V_16 ;
V_54 = F_42 ( V_11 , V_29 , V_68 ) ;
if ( V_54 ) {
F_15 ( V_5 ) ;
return V_54 ;
}
( (struct V_1 * ) V_11 -> V_15 ) -> V_5 = V_5 ;
( (struct V_1 * ) V_11 -> V_15 ) -> V_4 = V_4 ;
return 0 ;
}
int F_44 ( struct V_51 * V_51 , struct V_11 * V_11 )
{
const struct V_12 * V_13 = ( (struct V_1 * ) V_11 -> V_15 ) -> V_13 ;
int V_60 = F_23 ( V_51 , V_11 ) ;
F_24 ( V_13 ) ;
return V_60 ;
}
int F_45 ( struct V_51 * V_51 , struct V_11 * V_11 )
{
struct V_1 * V_70 = V_11 -> V_15 ;
F_24 ( V_70 -> V_69 ) ;
V_70 -> V_69 = NULL ;
return F_23 ( V_51 , V_11 ) ;
}
void * F_46 ( struct V_11 * V_56 , const struct V_12 * V_71 ,
int V_72 )
{
int V_73 ;
void * V_69 ;
struct V_1 * V_70 ;
V_69 = F_7 ( V_72 , V_7 ) ;
if ( V_69 == NULL )
goto V_74;
V_73 = F_5 ( V_56 , V_71 ) ;
if ( V_73 < 0 )
goto V_75;
V_70 = V_56 -> V_15 ;
V_70 -> V_69 = V_69 ;
return V_69 ;
V_75:
F_24 ( V_69 ) ;
V_74:
return NULL ;
}
int F_47 ( struct V_11 * V_76 , const struct V_12 * V_71 ,
int V_72 )
{
return F_46 ( V_76 , V_71 , V_72 ) ? 0 : - V_16 ;
}
void F_48 ( struct V_1 * V_2 , char V_58 )
{
if ( V_2 -> V_3 >= V_2 -> V_4 )
return;
V_2 -> V_5 [ V_2 -> V_3 ++ ] = V_58 ;
}
void F_49 ( struct V_1 * V_2 , const char * V_52 )
{
int V_57 = strlen ( V_52 ) ;
if ( V_2 -> V_3 + V_57 >= V_2 -> V_4 ) {
F_1 ( V_2 ) ;
return;
}
memcpy ( V_2 -> V_5 + V_2 -> V_3 , V_52 , V_57 ) ;
V_2 -> V_3 += V_57 ;
}
void F_50 ( struct V_1 * V_2 , char V_77 ,
unsigned long long V_78 )
{
int V_57 ;
if ( V_2 -> V_3 + 2 >= V_2 -> V_4 )
goto V_79;
if ( V_77 )
V_2 -> V_5 [ V_2 -> V_3 ++ ] = V_77 ;
if ( V_78 < 10 ) {
V_2 -> V_5 [ V_2 -> V_3 ++ ] = V_78 + '0' ;
return;
}
V_57 = F_51 ( V_2 -> V_5 + V_2 -> V_3 , V_2 -> V_4 - V_2 -> V_3 , V_78 ) ;
if ( ! V_57 )
goto V_79;
V_2 -> V_3 += V_57 ;
return;
V_79:
F_1 ( V_2 ) ;
}
void F_52 ( struct V_1 * V_2 , char V_77 , long long V_78 )
{
if ( V_78 < 0 ) {
if ( V_2 -> V_3 + 3 >= V_2 -> V_4 ) {
F_1 ( V_2 ) ;
return;
}
if ( V_77 )
V_2 -> V_5 [ V_2 -> V_3 ++ ] = V_77 ;
V_78 = - V_78 ;
V_77 = '-' ;
}
F_50 ( V_2 , V_77 , V_78 ) ;
}
int F_53 ( struct V_1 * V_70 , const void * V_68 , T_5 V_57 )
{
if ( V_70 -> V_3 + V_57 < V_70 -> V_4 ) {
memcpy ( V_70 -> V_5 + V_70 -> V_3 , V_68 , V_57 ) ;
V_70 -> V_3 += V_57 ;
return 0 ;
}
F_1 ( V_70 ) ;
return - 1 ;
}
void F_54 ( struct V_1 * V_2 , char V_58 )
{
int V_4 = V_2 -> V_80 - V_2 -> V_3 ;
if ( V_4 > 0 )
F_30 ( V_2 , L_1 , V_4 , L_2 ) ;
if ( V_58 )
F_48 ( V_2 , V_58 ) ;
}
void F_55 ( struct V_1 * V_2 , const char * V_81 , int V_82 ,
int V_83 , int V_84 , const void * V_5 , T_5 V_57 ,
bool V_85 )
{
const T_7 * V_86 = V_5 ;
int V_87 , V_88 , V_89 = V_57 ;
char * V_90 ;
T_5 V_4 ;
int V_54 ;
if ( V_83 != 16 && V_83 != 32 )
V_83 = 16 ;
for ( V_87 = 0 ; V_87 < V_57 && ! F_14 ( V_2 ) ; V_87 += V_83 ) {
V_88 = F_18 ( V_89 , V_83 ) ;
V_89 -= V_83 ;
switch ( V_82 ) {
case V_91 :
F_30 ( V_2 , L_3 , V_81 , V_86 + V_87 ) ;
break;
case V_92 :
F_30 ( V_2 , L_4 , V_81 , V_87 ) ;
break;
default:
F_30 ( V_2 , L_5 , V_81 ) ;
break;
}
V_4 = F_26 ( V_2 , & V_90 ) ;
V_54 = F_56 ( V_86 + V_87 , V_88 , V_83 , V_84 ,
V_90 , V_4 , V_85 ) ;
F_28 ( V_2 , V_54 < V_4 ? V_54 : - 1 ) ;
F_48 ( V_2 , '\n' ) ;
}
}
struct V_93 * F_57 ( struct V_93 * V_94 , T_2 V_24 )
{
struct V_93 * V_95 ;
F_58 (lh, head)
if ( V_24 -- == 0 )
return V_95 ;
return NULL ;
}
struct V_93 * F_59 ( struct V_93 * V_94 , T_2 V_24 )
{
if ( ! V_24 )
return V_94 ;
return F_57 ( V_94 , V_24 - 1 ) ;
}
struct V_93 * F_60 ( void * V_67 , struct V_93 * V_94 , T_2 * V_34 )
{
struct V_93 * V_95 ;
V_95 = ( (struct V_93 * ) V_67 ) -> V_31 ;
++ * V_34 ;
return V_95 == V_94 ? NULL : V_95 ;
}
struct V_96 * F_61 ( struct V_97 * V_94 , T_2 V_24 )
{
struct V_96 * V_98 ;
F_62 (node, head)
if ( V_24 -- == 0 )
return V_98 ;
return NULL ;
}
struct V_96 * F_63 ( struct V_97 * V_94 , T_2 V_24 )
{
if ( ! V_24 )
return V_99 ;
return F_61 ( V_94 , V_24 - 1 ) ;
}
struct V_96 * F_64 ( void * V_67 , struct V_97 * V_94 ,
T_2 * V_34 )
{
struct V_96 * V_98 = V_67 ;
++ * V_34 ;
if ( V_67 == V_99 )
return V_94 -> V_100 ;
else
return V_98 -> V_31 ;
}
struct V_96 * F_65 ( struct V_97 * V_94 ,
T_2 V_24 )
{
struct V_96 * V_98 ;
F_66 (node, head)
if ( V_24 -- == 0 )
return V_98 ;
return NULL ;
}
struct V_96 * F_67 ( struct V_97 * V_94 ,
T_2 V_24 )
{
if ( ! V_24 )
return V_99 ;
return F_65 ( V_94 , V_24 - 1 ) ;
}
struct V_96 * F_68 ( void * V_67 ,
struct V_97 * V_94 ,
T_2 * V_34 )
{
struct V_96 * V_98 = V_67 ;
++ * V_34 ;
if ( V_67 == V_99 )
return F_69 ( V_94 -> V_100 ) ;
else
return F_69 ( V_98 -> V_31 ) ;
}
struct V_96 *
F_70 ( struct V_97 T_8 * V_94 , int * V_101 , T_2 V_24 )
{
struct V_96 * V_98 ;
F_71 (*cpu) {
F_62 (node, per_cpu_ptr(head, *cpu)) {
if ( V_24 -- == 0 )
return V_98 ;
}
}
return NULL ;
}
struct V_96 *
F_72 ( void * V_67 , struct V_97 T_8 * V_94 ,
int * V_101 , T_2 * V_24 )
{
struct V_96 * V_98 = V_67 ;
++ * V_24 ;
if ( V_98 -> V_31 )
return V_98 -> V_31 ;
for ( * V_101 = F_73 ( * V_101 , V_102 ) ; * V_101 < V_103 ;
* V_101 = F_73 ( * V_101 , V_102 ) ) {
struct V_97 * V_104 = F_74 ( V_94 , * V_101 ) ;
if ( ! F_75 ( V_104 ) )
return V_104 -> V_100 ;
}
return NULL ;
}
