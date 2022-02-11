static bool F_1 ( struct V_1 * V_2 )
{
return V_2 -> V_3 == V_2 -> V_4 ;
}
static void F_2 ( struct V_1 * V_2 )
{
V_2 -> V_3 = V_2 -> V_4 ;
}
static void * F_3 ( unsigned long V_4 )
{
void * V_5 ;
V_5 = F_4 ( V_4 , V_6 | V_7 ) ;
if ( ! V_5 && V_4 > V_8 )
V_5 = F_5 ( V_4 ) ;
return V_5 ;
}
int F_6 ( struct V_9 * V_9 , const struct V_10 * V_11 )
{
struct V_1 * V_12 = V_9 -> V_13 ;
if ( ! V_12 ) {
V_12 = F_4 ( sizeof( * V_12 ) , V_6 ) ;
if ( ! V_12 )
return - V_14 ;
V_9 -> V_13 = V_12 ;
}
memset ( V_12 , 0 , sizeof( * V_12 ) ) ;
F_7 ( & V_12 -> V_15 ) ;
V_12 -> V_11 = V_11 ;
#ifdef F_8
V_12 -> V_16 = V_9 -> V_17 -> V_16 ;
#endif
V_9 -> V_18 = 0 ;
V_9 -> V_19 &= ~ V_20 ;
return 0 ;
}
static int F_9 ( struct V_1 * V_2 , T_1 V_21 )
{
T_1 V_22 = 0 , V_23 ;
int error = 0 ;
void * V_12 ;
V_2 -> V_24 = 0 ;
V_23 = 0 ;
V_2 -> V_3 = V_2 -> V_25 = 0 ;
if ( ! V_21 ) {
V_2 -> V_23 = V_23 ;
return 0 ;
}
if ( ! V_2 -> V_5 ) {
V_2 -> V_5 = F_3 ( V_2 -> V_4 = V_8 ) ;
if ( ! V_2 -> V_5 )
return - V_14 ;
}
V_12 = V_2 -> V_11 -> V_26 ( V_2 , & V_23 ) ;
while ( V_12 ) {
error = F_10 ( V_12 ) ;
if ( F_11 ( V_12 ) )
break;
error = V_2 -> V_11 -> V_27 ( V_2 , V_12 ) ;
if ( error < 0 )
break;
if ( F_12 ( error ) ) {
error = 0 ;
V_2 -> V_3 = 0 ;
}
if ( F_1 ( V_2 ) )
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
V_12 = V_2 -> V_11 -> V_29 ( V_2 , V_12 , & V_23 ) ;
}
V_2 -> V_11 -> V_30 ( V_2 , V_12 ) ;
V_2 -> V_23 = V_23 ;
return error ;
V_28:
V_2 -> V_11 -> V_30 ( V_2 , V_12 ) ;
F_13 ( V_2 -> V_5 ) ;
V_2 -> V_3 = 0 ;
V_2 -> V_5 = F_3 ( V_2 -> V_4 <<= 1 ) ;
return ! V_2 -> V_5 ? - V_14 : - V_31 ;
}
T_2 F_14 ( struct V_9 * V_9 , char T_3 * V_5 , T_4 V_4 , T_1 * V_32 )
{
struct V_1 * V_2 = V_9 -> V_13 ;
T_4 V_33 = 0 ;
T_1 V_22 ;
T_4 V_34 ;
void * V_12 ;
int V_35 = 0 ;
F_15 ( & V_2 -> V_15 ) ;
V_2 -> V_24 = V_9 -> V_18 ;
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
V_2 -> V_5 = F_3 ( V_2 -> V_4 = V_8 ) ;
if ( ! V_2 -> V_5 )
goto V_38;
}
if ( V_2 -> V_3 ) {
V_34 = F_16 ( V_2 -> V_3 , V_4 ) ;
V_35 = F_17 ( V_5 , V_2 -> V_5 + V_2 -> V_25 , V_34 ) ;
if ( V_35 )
goto V_39;
V_2 -> V_3 -= V_34 ;
V_2 -> V_25 += V_34 ;
V_4 -= V_34 ;
V_5 += V_34 ;
V_33 += V_34 ;
if ( ! V_2 -> V_3 )
V_2 -> V_23 ++ ;
if ( ! V_4 )
goto V_37;
}
V_22 = V_2 -> V_23 ;
V_12 = V_2 -> V_11 -> V_26 ( V_2 , & V_22 ) ;
while ( 1 ) {
V_35 = F_10 ( V_12 ) ;
if ( ! V_12 || F_11 ( V_12 ) )
break;
V_35 = V_2 -> V_11 -> V_27 ( V_2 , V_12 ) ;
if ( V_35 < 0 )
break;
if ( F_12 ( V_35 ) )
V_2 -> V_3 = 0 ;
if ( F_12 ( ! V_2 -> V_3 ) ) {
V_12 = V_2 -> V_11 -> V_29 ( V_2 , V_12 , & V_22 ) ;
V_2 -> V_23 = V_22 ;
continue;
}
if ( V_2 -> V_3 < V_2 -> V_4 )
goto V_40;
V_2 -> V_11 -> V_30 ( V_2 , V_12 ) ;
F_13 ( V_2 -> V_5 ) ;
V_2 -> V_3 = 0 ;
V_2 -> V_5 = F_3 ( V_2 -> V_4 <<= 1 ) ;
if ( ! V_2 -> V_5 )
goto V_38;
V_2 -> V_24 = 0 ;
V_22 = V_2 -> V_23 ;
V_12 = V_2 -> V_11 -> V_26 ( V_2 , & V_22 ) ;
}
V_2 -> V_11 -> V_30 ( V_2 , V_12 ) ;
V_2 -> V_3 = 0 ;
goto V_37;
V_40:
while ( V_2 -> V_3 < V_4 ) {
T_4 V_41 = V_2 -> V_3 ;
T_1 V_29 = V_22 ;
V_12 = V_2 -> V_11 -> V_29 ( V_2 , V_12 , & V_29 ) ;
if ( ! V_12 || F_11 ( V_12 ) ) {
V_35 = F_10 ( V_12 ) ;
break;
}
V_35 = V_2 -> V_11 -> V_27 ( V_2 , V_12 ) ;
if ( F_1 ( V_2 ) || V_35 ) {
V_2 -> V_3 = V_41 ;
if ( F_18 ( V_35 <= 0 ) )
break;
}
V_22 = V_29 ;
}
V_2 -> V_11 -> V_30 ( V_2 , V_12 ) ;
V_34 = F_16 ( V_2 -> V_3 , V_4 ) ;
V_35 = F_17 ( V_5 , V_2 -> V_5 , V_34 ) ;
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
V_9 -> V_18 = V_2 -> V_24 ;
F_19 ( & V_2 -> V_15 ) ;
return V_33 ;
V_38:
V_35 = - V_14 ;
goto V_37;
V_39:
V_35 = - V_42 ;
goto V_37;
}
T_1 F_20 ( struct V_9 * V_9 , T_1 V_21 , int V_43 )
{
struct V_1 * V_2 = V_9 -> V_13 ;
T_1 V_44 = - V_45 ;
F_15 ( & V_2 -> V_15 ) ;
V_2 -> V_24 = V_9 -> V_18 ;
switch ( V_43 ) {
case V_46 :
V_21 += V_9 -> V_47 ;
case V_48 :
if ( V_21 < 0 )
break;
V_44 = V_21 ;
if ( V_21 != V_2 -> V_36 ) {
while ( ( V_44 = F_9 ( V_2 , V_21 ) ) == - V_31 )
;
if ( V_44 ) {
V_9 -> V_47 = 0 ;
V_2 -> V_36 = 0 ;
V_2 -> V_24 = 0 ;
V_2 -> V_23 = 0 ;
V_2 -> V_3 = 0 ;
} else {
V_2 -> V_36 = V_21 ;
V_44 = V_9 -> V_47 = V_21 ;
}
} else {
V_9 -> V_47 = V_21 ;
}
}
V_9 -> V_18 = V_2 -> V_24 ;
F_19 ( & V_2 -> V_15 ) ;
return V_44 ;
}
int F_21 ( struct V_49 * V_49 , struct V_9 * V_9 )
{
struct V_1 * V_2 = V_9 -> V_13 ;
F_13 ( V_2 -> V_5 ) ;
F_22 ( V_2 ) ;
return 0 ;
}
int F_23 ( struct V_1 * V_2 , const char * V_50 , const char * V_51 )
{
char * V_52 = V_2 -> V_5 + V_2 -> V_4 ;
char * V_12 ;
char V_53 ;
for ( V_12 = V_2 -> V_5 + V_2 -> V_3 ; ( V_53 = * V_50 ) != '\0' && V_12 < V_52 ; V_50 ++ ) {
if ( ! strchr ( V_51 , V_53 ) ) {
* V_12 ++ = V_53 ;
continue;
}
if ( V_12 + 3 < V_52 ) {
* V_12 ++ = '\\' ;
* V_12 ++ = '0' + ( ( V_53 & 0300 ) >> 6 ) ;
* V_12 ++ = '0' + ( ( V_53 & 070 ) >> 3 ) ;
* V_12 ++ = '0' + ( V_53 & 07 ) ;
continue;
}
F_2 ( V_2 ) ;
return - 1 ;
}
V_2 -> V_3 = V_12 - V_2 -> V_5 ;
return 0 ;
}
int F_24 ( struct V_1 * V_2 , const char * V_54 , T_5 args )
{
int V_55 ;
if ( V_2 -> V_3 < V_2 -> V_4 ) {
V_55 = vsnprintf ( V_2 -> V_5 + V_2 -> V_3 , V_2 -> V_4 - V_2 -> V_3 , V_54 , args ) ;
if ( V_2 -> V_3 + V_55 < V_2 -> V_4 ) {
V_2 -> V_3 += V_55 ;
return 0 ;
}
}
F_2 ( V_2 ) ;
return - 1 ;
}
int F_25 ( struct V_1 * V_2 , const char * V_54 , ... )
{
int V_56 ;
T_5 args ;
va_start ( args , V_54 ) ;
V_56 = F_24 ( V_2 , V_54 , args ) ;
va_end ( args ) ;
return V_56 ;
}
char * F_26 ( char * V_50 , const char * V_12 , const char * V_51 )
{
while ( V_50 <= V_12 ) {
char V_53 = * V_12 ++ ;
if ( ! V_53 ) {
return V_50 ;
} else if ( ! strchr ( V_51 , V_53 ) ) {
* V_50 ++ = V_53 ;
} else if ( V_50 + 4 > V_12 ) {
break;
} else {
* V_50 ++ = '\\' ;
* V_50 ++ = '0' + ( ( V_53 & 0300 ) >> 6 ) ;
* V_50 ++ = '0' + ( ( V_53 & 070 ) >> 3 ) ;
* V_50 ++ = '0' + ( V_53 & 07 ) ;
}
}
return NULL ;
}
int F_27 ( struct V_1 * V_2 , const struct V_57 * V_57 , const char * V_51 )
{
char * V_5 ;
T_4 V_4 = F_28 ( V_2 , & V_5 ) ;
int V_58 = - 1 ;
if ( V_4 ) {
char * V_12 = F_29 ( V_57 , V_5 , V_4 ) ;
if ( ! F_11 ( V_12 ) ) {
char * V_52 = F_26 ( V_5 , V_12 , V_51 ) ;
if ( V_52 )
V_58 = V_52 - V_5 ;
}
}
F_30 ( V_2 , V_58 ) ;
return V_58 ;
}
int F_31 ( struct V_1 * V_2 , const struct V_57 * V_57 ,
const struct V_57 * V_59 , const char * V_51 )
{
char * V_5 ;
T_4 V_4 = F_28 ( V_2 , & V_5 ) ;
int V_58 = - V_60 ;
if ( V_4 ) {
char * V_12 ;
V_12 = F_32 ( V_57 , V_59 , V_5 , V_4 ) ;
if ( ! V_12 )
return V_61 ;
V_58 = F_10 ( V_12 ) ;
if ( ! F_11 ( V_12 ) ) {
char * V_52 = F_26 ( V_5 , V_12 , V_51 ) ;
if ( V_52 )
V_58 = V_52 - V_5 ;
else
V_58 = - V_60 ;
}
}
F_30 ( V_2 , V_58 ) ;
return V_58 < 0 && V_58 != - V_60 ? V_58 : 0 ;
}
int F_33 ( struct V_1 * V_2 , struct V_62 * V_62 , const char * V_51 )
{
char * V_5 ;
T_4 V_4 = F_28 ( V_2 , & V_5 ) ;
int V_58 = - 1 ;
if ( V_4 ) {
char * V_12 = F_34 ( V_62 , V_5 , V_4 ) ;
if ( ! F_11 ( V_12 ) ) {
char * V_52 = F_26 ( V_5 , V_12 , V_51 ) ;
if ( V_52 )
V_58 = V_52 - V_5 ;
}
}
F_30 ( V_2 , V_58 ) ;
return V_58 ;
}
int F_35 ( struct V_1 * V_2 , const unsigned long * V_63 ,
unsigned int V_64 )
{
if ( V_2 -> V_3 < V_2 -> V_4 ) {
int V_55 = F_36 ( V_2 -> V_5 + V_2 -> V_3 ,
V_2 -> V_4 - V_2 -> V_3 , V_63 , V_64 ) ;
if ( V_2 -> V_3 + V_55 < V_2 -> V_4 ) {
V_2 -> V_3 += V_55 ;
return 0 ;
}
}
F_2 ( V_2 ) ;
return - 1 ;
}
int F_37 ( struct V_1 * V_2 , const unsigned long * V_63 ,
unsigned int V_64 )
{
if ( V_2 -> V_3 < V_2 -> V_4 ) {
int V_55 = F_38 ( V_2 -> V_5 + V_2 -> V_3 ,
V_2 -> V_4 - V_2 -> V_3 , V_63 , V_64 ) ;
if ( V_2 -> V_3 + V_55 < V_2 -> V_4 ) {
V_2 -> V_3 += V_55 ;
return 0 ;
}
}
F_2 ( V_2 ) ;
return - 1 ;
}
static void * F_39 ( struct V_1 * V_12 , T_1 * V_22 )
{
return NULL + ( * V_22 == 0 ) ;
}
static void * F_40 ( struct V_1 * V_12 , void * V_65 , T_1 * V_22 )
{
++ * V_22 ;
return NULL ;
}
static void F_41 ( struct V_1 * V_12 , void * V_65 )
{
}
int F_42 ( struct V_9 * V_9 , int (* V_27)( struct V_1 * , void * ) ,
void * V_66 )
{
struct V_10 * V_11 = F_4 ( sizeof( * V_11 ) , V_6 ) ;
int V_58 = - V_14 ;
if ( V_11 ) {
V_11 -> V_26 = F_39 ;
V_11 -> V_29 = F_40 ;
V_11 -> V_30 = F_41 ;
V_11 -> V_27 = V_27 ;
V_58 = F_6 ( V_9 , V_11 ) ;
if ( ! V_58 )
( (struct V_1 * ) V_9 -> V_13 ) -> V_67 = V_66 ;
else
F_22 ( V_11 ) ;
}
return V_58 ;
}
int F_43 ( struct V_9 * V_9 , int (* V_27)( struct V_1 * , void * ) ,
void * V_66 , T_4 V_4 )
{
char * V_5 = F_3 ( V_4 ) ;
int V_56 ;
if ( ! V_5 )
return - V_14 ;
V_56 = F_42 ( V_9 , V_27 , V_66 ) ;
if ( V_56 ) {
F_13 ( V_5 ) ;
return V_56 ;
}
( (struct V_1 * ) V_9 -> V_13 ) -> V_5 = V_5 ;
( (struct V_1 * ) V_9 -> V_13 ) -> V_4 = V_4 ;
return 0 ;
}
int F_44 ( struct V_49 * V_49 , struct V_9 * V_9 )
{
const struct V_10 * V_11 = ( (struct V_1 * ) V_9 -> V_13 ) -> V_11 ;
int V_58 = F_21 ( V_49 , V_9 ) ;
F_22 ( V_11 ) ;
return V_58 ;
}
int F_45 ( struct V_49 * V_49 , struct V_9 * V_9 )
{
struct V_1 * V_68 = V_9 -> V_13 ;
F_22 ( V_68 -> V_67 ) ;
V_68 -> V_67 = NULL ;
return F_21 ( V_49 , V_9 ) ;
}
void * F_46 ( struct V_9 * V_54 , const struct V_10 * V_69 ,
int V_70 )
{
int V_71 ;
void * V_67 ;
struct V_1 * V_68 ;
V_67 = F_47 ( V_70 , V_6 ) ;
if ( V_67 == NULL )
goto V_72;
V_71 = F_6 ( V_54 , V_69 ) ;
if ( V_71 < 0 )
goto V_73;
V_68 = V_54 -> V_13 ;
V_68 -> V_67 = V_67 ;
return V_67 ;
V_73:
F_22 ( V_67 ) ;
V_72:
return NULL ;
}
int F_48 ( struct V_9 * V_74 , const struct V_10 * V_69 ,
int V_70 )
{
return F_46 ( V_74 , V_69 , V_70 ) ? 0 : - V_14 ;
}
int F_49 ( struct V_1 * V_2 , char V_53 )
{
if ( V_2 -> V_3 < V_2 -> V_4 ) {
V_2 -> V_5 [ V_2 -> V_3 ++ ] = V_53 ;
return 0 ;
}
return - 1 ;
}
int F_50 ( struct V_1 * V_2 , const char * V_50 )
{
int V_55 = strlen ( V_50 ) ;
if ( V_2 -> V_3 + V_55 < V_2 -> V_4 ) {
memcpy ( V_2 -> V_5 + V_2 -> V_3 , V_50 , V_55 ) ;
V_2 -> V_3 += V_55 ;
return 0 ;
}
F_2 ( V_2 ) ;
return - 1 ;
}
int F_51 ( struct V_1 * V_2 , char V_75 ,
unsigned long long V_76 )
{
int V_55 ;
if ( V_2 -> V_3 + 2 >= V_2 -> V_4 )
goto V_77;
if ( V_75 )
V_2 -> V_5 [ V_2 -> V_3 ++ ] = V_75 ;
if ( V_76 < 10 ) {
V_2 -> V_5 [ V_2 -> V_3 ++ ] = V_76 + '0' ;
return 0 ;
}
V_55 = F_52 ( V_2 -> V_5 + V_2 -> V_3 , V_2 -> V_4 - V_2 -> V_3 , V_76 ) ;
if ( ! V_55 )
goto V_77;
V_2 -> V_3 += V_55 ;
return 0 ;
V_77:
F_2 ( V_2 ) ;
return - 1 ;
}
int F_53 ( struct V_1 * V_2 , char V_75 ,
long long V_76 )
{
if ( V_76 < 0 ) {
if ( V_2 -> V_3 + 3 >= V_2 -> V_4 ) {
F_2 ( V_2 ) ;
return - 1 ;
}
if ( V_75 )
V_2 -> V_5 [ V_2 -> V_3 ++ ] = V_75 ;
V_76 = - V_76 ;
V_75 = '-' ;
}
return F_51 ( V_2 , V_75 , V_76 ) ;
}
int F_54 ( struct V_1 * V_68 , const void * V_66 , T_4 V_55 )
{
if ( V_68 -> V_3 + V_55 < V_68 -> V_4 ) {
memcpy ( V_68 -> V_5 + V_68 -> V_3 , V_66 , V_55 ) ;
V_68 -> V_3 += V_55 ;
return 0 ;
}
F_2 ( V_68 ) ;
return - 1 ;
}
void F_55 ( struct V_1 * V_2 , char V_53 )
{
int V_4 = V_2 -> V_78 - V_2 -> V_3 ;
if ( V_4 > 0 )
F_25 ( V_2 , L_1 , V_4 , L_2 ) ;
if ( V_53 )
F_49 ( V_2 , V_53 ) ;
}
struct V_79 * F_56 ( struct V_79 * V_80 , T_1 V_22 )
{
struct V_79 * V_81 ;
F_57 (lh, head)
if ( V_22 -- == 0 )
return V_81 ;
return NULL ;
}
struct V_79 * F_58 ( struct V_79 * V_80 , T_1 V_22 )
{
if ( ! V_22 )
return V_80 ;
return F_56 ( V_80 , V_22 - 1 ) ;
}
struct V_79 * F_59 ( void * V_65 , struct V_79 * V_80 , T_1 * V_32 )
{
struct V_79 * V_81 ;
V_81 = ( (struct V_79 * ) V_65 ) -> V_29 ;
++ * V_32 ;
return V_81 == V_80 ? NULL : V_81 ;
}
struct V_82 * F_60 ( struct V_83 * V_80 , T_1 V_22 )
{
struct V_82 * V_84 ;
F_61 (node, head)
if ( V_22 -- == 0 )
return V_84 ;
return NULL ;
}
struct V_82 * F_62 ( struct V_83 * V_80 , T_1 V_22 )
{
if ( ! V_22 )
return V_85 ;
return F_60 ( V_80 , V_22 - 1 ) ;
}
struct V_82 * F_63 ( void * V_65 , struct V_83 * V_80 ,
T_1 * V_32 )
{
struct V_82 * V_84 = V_65 ;
++ * V_32 ;
if ( V_65 == V_85 )
return V_80 -> V_86 ;
else
return V_84 -> V_29 ;
}
struct V_82 * F_64 ( struct V_83 * V_80 ,
T_1 V_22 )
{
struct V_82 * V_84 ;
F_65 (node, head)
if ( V_22 -- == 0 )
return V_84 ;
return NULL ;
}
struct V_82 * F_66 ( struct V_83 * V_80 ,
T_1 V_22 )
{
if ( ! V_22 )
return V_85 ;
return F_64 ( V_80 , V_22 - 1 ) ;
}
struct V_82 * F_67 ( void * V_65 ,
struct V_83 * V_80 ,
T_1 * V_32 )
{
struct V_82 * V_84 = V_65 ;
++ * V_32 ;
if ( V_65 == V_85 )
return F_68 ( V_80 -> V_86 ) ;
else
return F_68 ( V_84 -> V_29 ) ;
}
struct V_82 *
F_69 ( struct V_83 T_6 * V_80 , int * V_87 , T_1 V_22 )
{
struct V_82 * V_84 ;
F_70 (*cpu) {
F_61 (node, per_cpu_ptr(head, *cpu)) {
if ( V_22 -- == 0 )
return V_84 ;
}
}
return NULL ;
}
struct V_82 *
F_71 ( void * V_65 , struct V_83 T_6 * V_80 ,
int * V_87 , T_1 * V_22 )
{
struct V_82 * V_84 = V_65 ;
++ * V_22 ;
if ( V_84 -> V_29 )
return V_84 -> V_29 ;
for ( * V_87 = F_72 ( * V_87 , V_88 ) ; * V_87 < V_89 ;
* V_87 = F_72 ( * V_87 , V_88 ) ) {
struct V_83 * V_90 = F_73 ( V_80 , * V_87 ) ;
if ( ! F_74 ( V_90 ) )
return V_90 -> V_86 ;
}
return NULL ;
}
