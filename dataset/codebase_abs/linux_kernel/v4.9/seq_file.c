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
V_14 -> V_11 = V_11 ;
V_11 -> V_18 = 0 ;
V_11 -> V_19 &= ~ V_20 ;
return 0 ;
}
static int F_9 ( struct V_1 * V_2 , T_2 V_21 )
{
T_2 V_22 = 0 , V_23 ;
int error = 0 ;
void * V_14 ;
V_2 -> V_24 = 0 ;
V_23 = 0 ;
V_2 -> V_3 = V_2 -> V_25 = 0 ;
if ( ! V_21 ) {
V_2 -> V_23 = V_23 ;
return 0 ;
}
if ( ! V_2 -> V_5 ) {
V_2 -> V_5 = F_2 ( V_2 -> V_4 = V_8 ) ;
if ( ! V_2 -> V_5 )
return - V_16 ;
}
V_14 = V_2 -> V_13 -> V_26 ( V_2 , & V_23 ) ;
while ( V_14 ) {
error = F_10 ( V_14 ) ;
if ( F_11 ( V_14 ) )
break;
error = V_2 -> V_13 -> V_27 ( V_2 , V_14 ) ;
if ( error < 0 )
break;
if ( F_12 ( error ) ) {
error = 0 ;
V_2 -> V_3 = 0 ;
}
if ( F_13 ( V_2 ) )
goto V_28;
if ( V_22 + V_2 -> V_3 > V_21 ) {
V_2 -> V_25 = V_21 - V_22 ;
V_2 -> V_3 -= V_2 -> V_25 ;
V_2 -> V_23 = V_23 ;
break;
}
V_22 += V_2 -> V_3 ;
V_2 -> V_3 = 0 ;
if ( V_22 == V_21 ) {
V_23 ++ ;
V_2 -> V_23 = V_23 ;
break;
}
V_14 = V_2 -> V_13 -> V_29 ( V_2 , V_14 , & V_23 ) ;
}
V_2 -> V_13 -> V_30 ( V_2 , V_14 ) ;
V_2 -> V_23 = V_23 ;
return error ;
V_28:
V_2 -> V_13 -> V_30 ( V_2 , V_14 ) ;
F_14 ( V_2 -> V_5 ) ;
V_2 -> V_3 = 0 ;
V_2 -> V_5 = F_2 ( V_2 -> V_4 <<= 1 ) ;
return ! V_2 -> V_5 ? - V_16 : - V_31 ;
}
T_3 F_15 ( struct V_11 * V_11 , char T_4 * V_5 , T_5 V_4 , T_2 * V_32 )
{
struct V_1 * V_2 = V_11 -> V_15 ;
T_5 V_33 = 0 ;
T_2 V_22 ;
T_5 V_34 ;
void * V_14 ;
int V_35 = 0 ;
F_16 ( & V_2 -> V_17 ) ;
V_2 -> V_24 = V_11 -> V_18 ;
if ( F_12 ( * V_32 != V_2 -> V_36 ) ) {
while ( ( V_35 = F_9 ( V_2 , * V_32 ) ) == - V_31 )
;
if ( V_35 ) {
V_2 -> V_36 = 0 ;
V_2 -> V_24 = 0 ;
V_2 -> V_23 = 0 ;
V_2 -> V_3 = 0 ;
goto V_37;
} else {
V_2 -> V_36 = * V_32 ;
}
}
if ( ! V_2 -> V_5 ) {
V_2 -> V_5 = F_2 ( V_2 -> V_4 = V_8 ) ;
if ( ! V_2 -> V_5 )
goto V_38;
}
if ( V_2 -> V_3 ) {
V_34 = F_17 ( V_2 -> V_3 , V_4 ) ;
V_35 = F_18 ( V_5 , V_2 -> V_5 + V_2 -> V_25 , V_34 ) ;
if ( V_35 )
goto V_39;
V_2 -> V_3 -= V_34 ;
V_2 -> V_25 += V_34 ;
V_4 -= V_34 ;
V_5 += V_34 ;
V_33 += V_34 ;
if ( ! V_2 -> V_3 ) {
V_2 -> V_25 = 0 ;
V_2 -> V_23 ++ ;
}
if ( ! V_4 )
goto V_37;
}
V_22 = V_2 -> V_23 ;
V_14 = V_2 -> V_13 -> V_26 ( V_2 , & V_22 ) ;
while ( 1 ) {
V_35 = F_10 ( V_14 ) ;
if ( ! V_14 || F_11 ( V_14 ) )
break;
V_35 = V_2 -> V_13 -> V_27 ( V_2 , V_14 ) ;
if ( V_35 < 0 )
break;
if ( F_12 ( V_35 ) )
V_2 -> V_3 = 0 ;
if ( F_12 ( ! V_2 -> V_3 ) ) {
V_14 = V_2 -> V_13 -> V_29 ( V_2 , V_14 , & V_22 ) ;
V_2 -> V_23 = V_22 ;
continue;
}
if ( V_2 -> V_3 < V_2 -> V_4 )
goto V_40;
V_2 -> V_13 -> V_30 ( V_2 , V_14 ) ;
F_14 ( V_2 -> V_5 ) ;
V_2 -> V_3 = 0 ;
V_2 -> V_5 = F_2 ( V_2 -> V_4 <<= 1 ) ;
if ( ! V_2 -> V_5 )
goto V_38;
V_2 -> V_24 = 0 ;
V_22 = V_2 -> V_23 ;
V_14 = V_2 -> V_13 -> V_26 ( V_2 , & V_22 ) ;
}
V_2 -> V_13 -> V_30 ( V_2 , V_14 ) ;
V_2 -> V_3 = 0 ;
goto V_37;
V_40:
while ( V_2 -> V_3 < V_4 ) {
T_5 V_41 = V_2 -> V_3 ;
T_2 V_29 = V_22 ;
V_14 = V_2 -> V_13 -> V_29 ( V_2 , V_14 , & V_29 ) ;
if ( ! V_14 || F_11 ( V_14 ) ) {
V_35 = F_10 ( V_14 ) ;
break;
}
V_35 = V_2 -> V_13 -> V_27 ( V_2 , V_14 ) ;
if ( F_13 ( V_2 ) || V_35 ) {
V_2 -> V_3 = V_41 ;
if ( F_19 ( V_35 <= 0 ) )
break;
}
V_22 = V_29 ;
}
V_2 -> V_13 -> V_30 ( V_2 , V_14 ) ;
V_34 = F_17 ( V_2 -> V_3 , V_4 ) ;
V_35 = F_18 ( V_5 , V_2 -> V_5 , V_34 ) ;
if ( V_35 )
goto V_39;
V_33 += V_34 ;
V_2 -> V_3 -= V_34 ;
if ( V_2 -> V_3 )
V_2 -> V_25 = V_34 ;
else
V_22 ++ ;
V_2 -> V_23 = V_22 ;
V_37:
if ( ! V_33 )
V_33 = V_35 ;
else {
* V_32 += V_33 ;
V_2 -> V_36 += V_33 ;
}
V_11 -> V_18 = V_2 -> V_24 ;
F_20 ( & V_2 -> V_17 ) ;
return V_33 ;
V_38:
V_35 = - V_16 ;
goto V_37;
V_39:
V_35 = - V_42 ;
goto V_37;
}
T_2 F_21 ( struct V_11 * V_11 , T_2 V_21 , int V_43 )
{
struct V_1 * V_2 = V_11 -> V_15 ;
T_2 V_44 = - V_45 ;
F_16 ( & V_2 -> V_17 ) ;
V_2 -> V_24 = V_11 -> V_18 ;
switch ( V_43 ) {
case V_46 :
V_21 += V_11 -> V_47 ;
case V_48 :
if ( V_21 < 0 )
break;
V_44 = V_21 ;
if ( V_21 != V_2 -> V_36 ) {
while ( ( V_44 = F_9 ( V_2 , V_21 ) ) == - V_31 )
;
if ( V_44 ) {
V_11 -> V_47 = 0 ;
V_2 -> V_36 = 0 ;
V_2 -> V_24 = 0 ;
V_2 -> V_23 = 0 ;
V_2 -> V_3 = 0 ;
} else {
V_2 -> V_36 = V_21 ;
V_44 = V_11 -> V_47 = V_21 ;
}
} else {
V_11 -> V_47 = V_21 ;
}
}
V_11 -> V_18 = V_2 -> V_24 ;
F_20 ( & V_2 -> V_17 ) ;
return V_44 ;
}
int F_22 ( struct V_49 * V_49 , struct V_11 * V_11 )
{
struct V_1 * V_2 = V_11 -> V_15 ;
F_14 ( V_2 -> V_5 ) ;
F_23 ( V_2 ) ;
return 0 ;
}
void F_24 ( struct V_1 * V_2 , const char * V_50 , const char * V_51 )
{
char * V_5 ;
T_5 V_4 = F_25 ( V_2 , & V_5 ) ;
int V_52 ;
V_52 = F_26 ( V_50 , V_5 , V_4 , V_53 , V_51 ) ;
F_27 ( V_2 , V_52 < V_4 ? V_52 : - 1 ) ;
}
void F_28 ( struct V_1 * V_2 , const char * V_54 , T_6 args )
{
int V_55 ;
if ( V_2 -> V_3 < V_2 -> V_4 ) {
V_55 = vsnprintf ( V_2 -> V_5 + V_2 -> V_3 , V_2 -> V_4 - V_2 -> V_3 , V_54 , args ) ;
if ( V_2 -> V_3 + V_55 < V_2 -> V_4 ) {
V_2 -> V_3 += V_55 ;
return;
}
}
F_1 ( V_2 ) ;
}
void F_29 ( struct V_1 * V_2 , const char * V_54 , ... )
{
T_6 args ;
va_start ( args , V_54 ) ;
F_28 ( V_2 , V_54 , args ) ;
va_end ( args ) ;
}
char * F_30 ( char * V_50 , const char * V_14 , const char * V_51 )
{
while ( V_50 <= V_14 ) {
char V_56 = * V_14 ++ ;
if ( ! V_56 ) {
return V_50 ;
} else if ( ! strchr ( V_51 , V_56 ) ) {
* V_50 ++ = V_56 ;
} else if ( V_50 + 4 > V_14 ) {
break;
} else {
* V_50 ++ = '\\' ;
* V_50 ++ = '0' + ( ( V_56 & 0300 ) >> 6 ) ;
* V_50 ++ = '0' + ( ( V_56 & 070 ) >> 3 ) ;
* V_50 ++ = '0' + ( V_56 & 07 ) ;
}
}
return NULL ;
}
int F_31 ( struct V_1 * V_2 , const struct V_57 * V_57 , const char * V_51 )
{
char * V_5 ;
T_5 V_4 = F_25 ( V_2 , & V_5 ) ;
int V_58 = - 1 ;
if ( V_4 ) {
char * V_14 = F_32 ( V_57 , V_5 , V_4 ) ;
if ( ! F_11 ( V_14 ) ) {
char * V_59 = F_30 ( V_5 , V_14 , V_51 ) ;
if ( V_59 )
V_58 = V_59 - V_5 ;
}
}
F_27 ( V_2 , V_58 ) ;
return V_58 ;
}
int F_33 ( struct V_1 * V_2 , struct V_11 * V_11 , const char * V_51 )
{
return F_31 ( V_2 , & V_11 -> V_60 , V_51 ) ;
}
int F_34 ( struct V_1 * V_2 , const struct V_57 * V_57 ,
const struct V_57 * V_61 , const char * V_51 )
{
char * V_5 ;
T_5 V_4 = F_25 ( V_2 , & V_5 ) ;
int V_58 = - V_62 ;
if ( V_4 ) {
char * V_14 ;
V_14 = F_35 ( V_57 , V_61 , V_5 , V_4 ) ;
if ( ! V_14 )
return V_63 ;
V_58 = F_10 ( V_14 ) ;
if ( ! F_11 ( V_14 ) ) {
char * V_59 = F_30 ( V_5 , V_14 , V_51 ) ;
if ( V_59 )
V_58 = V_59 - V_5 ;
else
V_58 = - V_62 ;
}
}
F_27 ( V_2 , V_58 ) ;
return V_58 < 0 && V_58 != - V_62 ? V_58 : 0 ;
}
int F_36 ( struct V_1 * V_2 , struct V_64 * V_64 , const char * V_51 )
{
char * V_5 ;
T_5 V_4 = F_25 ( V_2 , & V_5 ) ;
int V_58 = - 1 ;
if ( V_4 ) {
char * V_14 = F_37 ( V_64 , V_5 , V_4 ) ;
if ( ! F_11 ( V_14 ) ) {
char * V_59 = F_30 ( V_5 , V_14 , V_51 ) ;
if ( V_59 )
V_58 = V_59 - V_5 ;
}
}
F_27 ( V_2 , V_58 ) ;
return V_58 ;
}
static void * F_38 ( struct V_1 * V_14 , T_2 * V_22 )
{
return NULL + ( * V_22 == 0 ) ;
}
static void * F_39 ( struct V_1 * V_14 , void * V_65 , T_2 * V_22 )
{
++ * V_22 ;
return NULL ;
}
static void F_40 ( struct V_1 * V_14 , void * V_65 )
{
}
int F_41 ( struct V_11 * V_11 , int (* V_27)( struct V_1 * , void * ) ,
void * V_66 )
{
struct V_12 * V_13 = F_3 ( sizeof( * V_13 ) , V_7 ) ;
int V_58 = - V_16 ;
if ( V_13 ) {
V_13 -> V_26 = F_38 ;
V_13 -> V_29 = F_39 ;
V_13 -> V_30 = F_40 ;
V_13 -> V_27 = V_27 ;
V_58 = F_5 ( V_11 , V_13 ) ;
if ( ! V_58 )
( (struct V_1 * ) V_11 -> V_15 ) -> V_67 = V_66 ;
else
F_23 ( V_13 ) ;
}
return V_58 ;
}
int F_42 ( struct V_11 * V_11 , int (* V_27)( struct V_1 * , void * ) ,
void * V_66 , T_5 V_4 )
{
char * V_5 = F_2 ( V_4 ) ;
int V_52 ;
if ( ! V_5 )
return - V_16 ;
V_52 = F_41 ( V_11 , V_27 , V_66 ) ;
if ( V_52 ) {
F_14 ( V_5 ) ;
return V_52 ;
}
( (struct V_1 * ) V_11 -> V_15 ) -> V_5 = V_5 ;
( (struct V_1 * ) V_11 -> V_15 ) -> V_4 = V_4 ;
return 0 ;
}
int F_43 ( struct V_49 * V_49 , struct V_11 * V_11 )
{
const struct V_12 * V_13 = ( (struct V_1 * ) V_11 -> V_15 ) -> V_13 ;
int V_58 = F_22 ( V_49 , V_11 ) ;
F_23 ( V_13 ) ;
return V_58 ;
}
int F_44 ( struct V_49 * V_49 , struct V_11 * V_11 )
{
struct V_1 * V_68 = V_11 -> V_15 ;
F_23 ( V_68 -> V_67 ) ;
V_68 -> V_67 = NULL ;
return F_22 ( V_49 , V_11 ) ;
}
void * F_45 ( struct V_11 * V_54 , const struct V_12 * V_69 ,
int V_70 )
{
int V_71 ;
void * V_67 ;
struct V_1 * V_68 ;
V_67 = F_7 ( V_70 , V_7 ) ;
if ( V_67 == NULL )
goto V_72;
V_71 = F_5 ( V_54 , V_69 ) ;
if ( V_71 < 0 )
goto V_73;
V_68 = V_54 -> V_15 ;
V_68 -> V_67 = V_67 ;
return V_67 ;
V_73:
F_23 ( V_67 ) ;
V_72:
return NULL ;
}
int F_46 ( struct V_11 * V_74 , const struct V_12 * V_69 ,
int V_70 )
{
return F_45 ( V_74 , V_69 , V_70 ) ? 0 : - V_16 ;
}
void F_47 ( struct V_1 * V_2 , char V_56 )
{
if ( V_2 -> V_3 >= V_2 -> V_4 )
return;
V_2 -> V_5 [ V_2 -> V_3 ++ ] = V_56 ;
}
void F_48 ( struct V_1 * V_2 , const char * V_50 )
{
int V_55 = strlen ( V_50 ) ;
if ( V_2 -> V_3 + V_55 >= V_2 -> V_4 ) {
F_1 ( V_2 ) ;
return;
}
memcpy ( V_2 -> V_5 + V_2 -> V_3 , V_50 , V_55 ) ;
V_2 -> V_3 += V_55 ;
}
void F_49 ( struct V_1 * V_2 , const char * V_75 ,
unsigned long long V_76 )
{
int V_55 ;
if ( V_2 -> V_3 + 2 >= V_2 -> V_4 )
goto V_77;
V_55 = strlen ( V_75 ) ;
if ( V_2 -> V_3 + V_55 >= V_2 -> V_4 )
goto V_77;
memcpy ( V_2 -> V_5 + V_2 -> V_3 , V_75 , V_55 ) ;
V_2 -> V_3 += V_55 ;
if ( V_2 -> V_3 + 1 >= V_2 -> V_4 )
goto V_77;
if ( V_76 < 10 ) {
V_2 -> V_5 [ V_2 -> V_3 ++ ] = V_76 + '0' ;
return;
}
V_55 = F_50 ( V_2 -> V_5 + V_2 -> V_3 , V_2 -> V_4 - V_2 -> V_3 , V_76 ) ;
if ( ! V_55 )
goto V_77;
V_2 -> V_3 += V_55 ;
return;
V_77:
F_1 ( V_2 ) ;
}
void F_51 ( struct V_1 * V_2 , const char * V_75 , long long V_76 )
{
int V_55 ;
if ( V_2 -> V_3 + 3 >= V_2 -> V_4 )
goto V_77;
V_55 = strlen ( V_75 ) ;
if ( V_2 -> V_3 + V_55 >= V_2 -> V_4 )
goto V_77;
memcpy ( V_2 -> V_5 + V_2 -> V_3 , V_75 , V_55 ) ;
V_2 -> V_3 += V_55 ;
if ( V_2 -> V_3 + 2 >= V_2 -> V_4 )
goto V_77;
if ( V_76 < 0 ) {
V_2 -> V_5 [ V_2 -> V_3 ++ ] = '-' ;
V_76 = - V_76 ;
}
if ( V_76 < 10 ) {
V_2 -> V_5 [ V_2 -> V_3 ++ ] = V_76 + '0' ;
return;
}
V_55 = F_50 ( V_2 -> V_5 + V_2 -> V_3 , V_2 -> V_4 - V_2 -> V_3 , V_76 ) ;
if ( ! V_55 )
goto V_77;
V_2 -> V_3 += V_55 ;
return;
V_77:
F_1 ( V_2 ) ;
}
int F_52 ( struct V_1 * V_68 , const void * V_66 , T_5 V_55 )
{
if ( V_68 -> V_3 + V_55 < V_68 -> V_4 ) {
memcpy ( V_68 -> V_5 + V_68 -> V_3 , V_66 , V_55 ) ;
V_68 -> V_3 += V_55 ;
return 0 ;
}
F_1 ( V_68 ) ;
return - 1 ;
}
void F_53 ( struct V_1 * V_2 , char V_56 )
{
int V_4 = V_2 -> V_78 - V_2 -> V_3 ;
if ( V_4 > 0 )
F_29 ( V_2 , L_1 , V_4 , L_2 ) ;
if ( V_56 )
F_47 ( V_2 , V_56 ) ;
}
void F_54 ( struct V_1 * V_2 , const char * V_79 , int V_80 ,
int V_81 , int V_82 , const void * V_5 , T_5 V_55 ,
bool V_83 )
{
const T_7 * V_84 = V_5 ;
int V_85 , V_86 , V_87 = V_55 ;
char * V_88 ;
T_5 V_4 ;
int V_52 ;
if ( V_81 != 16 && V_81 != 32 )
V_81 = 16 ;
for ( V_85 = 0 ; V_85 < V_55 && ! F_13 ( V_2 ) ; V_85 += V_81 ) {
V_86 = F_17 ( V_87 , V_81 ) ;
V_87 -= V_81 ;
switch ( V_80 ) {
case V_89 :
F_29 ( V_2 , L_3 , V_79 , V_84 + V_85 ) ;
break;
case V_90 :
F_29 ( V_2 , L_4 , V_79 , V_85 ) ;
break;
default:
F_29 ( V_2 , L_5 , V_79 ) ;
break;
}
V_4 = F_25 ( V_2 , & V_88 ) ;
V_52 = F_55 ( V_84 + V_85 , V_86 , V_81 , V_82 ,
V_88 , V_4 , V_83 ) ;
F_27 ( V_2 , V_52 < V_4 ? V_52 : - 1 ) ;
F_47 ( V_2 , '\n' ) ;
}
}
struct V_91 * F_56 ( struct V_91 * V_92 , T_2 V_22 )
{
struct V_91 * V_93 ;
F_57 (lh, head)
if ( V_22 -- == 0 )
return V_93 ;
return NULL ;
}
struct V_91 * F_58 ( struct V_91 * V_92 , T_2 V_22 )
{
if ( ! V_22 )
return V_92 ;
return F_56 ( V_92 , V_22 - 1 ) ;
}
struct V_91 * F_59 ( void * V_65 , struct V_91 * V_92 , T_2 * V_32 )
{
struct V_91 * V_93 ;
V_93 = ( (struct V_91 * ) V_65 ) -> V_29 ;
++ * V_32 ;
return V_93 == V_92 ? NULL : V_93 ;
}
struct V_94 * F_60 ( struct V_95 * V_92 , T_2 V_22 )
{
struct V_94 * V_96 ;
F_61 (node, head)
if ( V_22 -- == 0 )
return V_96 ;
return NULL ;
}
struct V_94 * F_62 ( struct V_95 * V_92 , T_2 V_22 )
{
if ( ! V_22 )
return V_97 ;
return F_60 ( V_92 , V_22 - 1 ) ;
}
struct V_94 * F_63 ( void * V_65 , struct V_95 * V_92 ,
T_2 * V_32 )
{
struct V_94 * V_96 = V_65 ;
++ * V_32 ;
if ( V_65 == V_97 )
return V_92 -> V_98 ;
else
return V_96 -> V_29 ;
}
struct V_94 * F_64 ( struct V_95 * V_92 ,
T_2 V_22 )
{
struct V_94 * V_96 ;
F_65 (node, head)
if ( V_22 -- == 0 )
return V_96 ;
return NULL ;
}
struct V_94 * F_66 ( struct V_95 * V_92 ,
T_2 V_22 )
{
if ( ! V_22 )
return V_97 ;
return F_64 ( V_92 , V_22 - 1 ) ;
}
struct V_94 * F_67 ( void * V_65 ,
struct V_95 * V_92 ,
T_2 * V_32 )
{
struct V_94 * V_96 = V_65 ;
++ * V_32 ;
if ( V_65 == V_97 )
return F_68 ( V_92 -> V_98 ) ;
else
return F_68 ( V_96 -> V_29 ) ;
}
struct V_94 *
F_69 ( struct V_95 T_8 * V_92 , int * V_99 , T_2 V_22 )
{
struct V_94 * V_96 ;
F_70 (*cpu) {
F_61 (node, per_cpu_ptr(head, *cpu)) {
if ( V_22 -- == 0 )
return V_96 ;
}
}
return NULL ;
}
struct V_94 *
F_71 ( void * V_65 , struct V_95 T_8 * V_92 ,
int * V_99 , T_2 * V_22 )
{
struct V_94 * V_96 = V_65 ;
++ * V_22 ;
if ( V_96 -> V_29 )
return V_96 -> V_29 ;
for ( * V_99 = F_72 ( * V_99 , V_100 ) ; * V_99 < V_101 ;
* V_99 = F_72 ( * V_99 , V_100 ) ) {
struct V_95 * V_102 = F_73 ( V_92 , * V_99 ) ;
if ( ! F_74 ( V_102 ) )
return V_102 -> V_98 ;
}
return NULL ;
}
