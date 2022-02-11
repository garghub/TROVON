static void F_1 ( struct V_1 * V_2 )
{
V_2 -> V_3 = V_2 -> V_4 ;
}
static void * F_2 ( unsigned long V_4 )
{
void * V_5 ;
V_5 = F_3 ( V_4 , V_6 | V_7 | V_8 ) ;
if ( ! V_5 && V_4 > V_9 )
V_5 = F_4 ( V_4 ) ;
return V_5 ;
}
int F_5 ( struct V_10 * V_10 , const struct V_11 * V_12 )
{
struct V_1 * V_13 = V_10 -> V_14 ;
if ( ! V_13 ) {
V_13 = F_3 ( sizeof( * V_13 ) , V_6 ) ;
if ( ! V_13 )
return - V_15 ;
V_10 -> V_14 = V_13 ;
}
memset ( V_13 , 0 , sizeof( * V_13 ) ) ;
F_6 ( & V_13 -> V_16 ) ;
V_13 -> V_12 = V_12 ;
#ifdef F_7
V_13 -> V_17 = V_10 -> V_18 -> V_17 ;
#endif
V_10 -> V_19 = 0 ;
V_10 -> V_20 &= ~ V_21 ;
return 0 ;
}
static int F_8 ( struct V_1 * V_2 , T_1 V_22 )
{
T_1 V_23 = 0 , V_24 ;
int error = 0 ;
void * V_13 ;
V_2 -> V_25 = 0 ;
V_24 = 0 ;
V_2 -> V_3 = V_2 -> V_26 = 0 ;
if ( ! V_22 ) {
V_2 -> V_24 = V_24 ;
return 0 ;
}
if ( ! V_2 -> V_5 ) {
V_2 -> V_5 = F_2 ( V_2 -> V_4 = V_9 ) ;
if ( ! V_2 -> V_5 )
return - V_15 ;
}
V_13 = V_2 -> V_12 -> V_27 ( V_2 , & V_24 ) ;
while ( V_13 ) {
error = F_9 ( V_13 ) ;
if ( F_10 ( V_13 ) )
break;
error = V_2 -> V_12 -> V_28 ( V_2 , V_13 ) ;
if ( error < 0 )
break;
if ( F_11 ( error ) ) {
error = 0 ;
V_2 -> V_3 = 0 ;
}
if ( F_12 ( V_2 ) )
goto V_29;
if ( V_23 + V_2 -> V_3 > V_22 ) {
V_2 -> V_26 = V_22 - V_23 ;
V_2 -> V_3 -= V_2 -> V_26 ;
V_2 -> V_24 = V_24 ;
break;
}
V_23 += V_2 -> V_3 ;
V_2 -> V_3 = 0 ;
if ( V_23 == V_22 ) {
V_24 ++ ;
V_2 -> V_24 = V_24 ;
break;
}
V_13 = V_2 -> V_12 -> V_30 ( V_2 , V_13 , & V_24 ) ;
}
V_2 -> V_12 -> V_31 ( V_2 , V_13 ) ;
V_2 -> V_24 = V_24 ;
return error ;
V_29:
V_2 -> V_12 -> V_31 ( V_2 , V_13 ) ;
F_13 ( V_2 -> V_5 ) ;
V_2 -> V_3 = 0 ;
V_2 -> V_5 = F_2 ( V_2 -> V_4 <<= 1 ) ;
return ! V_2 -> V_5 ? - V_15 : - V_32 ;
}
T_2 F_14 ( struct V_10 * V_10 , char T_3 * V_5 , T_4 V_4 , T_1 * V_33 )
{
struct V_1 * V_2 = V_10 -> V_14 ;
T_4 V_34 = 0 ;
T_1 V_23 ;
T_4 V_35 ;
void * V_13 ;
int V_36 = 0 ;
F_15 ( & V_2 -> V_16 ) ;
V_2 -> V_25 = V_10 -> V_19 ;
if ( F_11 ( * V_33 != V_2 -> V_37 ) ) {
while ( ( V_36 = F_8 ( V_2 , * V_33 ) ) == - V_32 )
;
if ( V_36 ) {
V_2 -> V_37 = 0 ;
V_2 -> V_25 = 0 ;
V_2 -> V_24 = 0 ;
V_2 -> V_3 = 0 ;
goto V_38;
} else {
V_2 -> V_37 = * V_33 ;
}
}
if ( ! V_2 -> V_5 ) {
V_2 -> V_5 = F_2 ( V_2 -> V_4 = V_9 ) ;
if ( ! V_2 -> V_5 )
goto V_39;
}
if ( V_2 -> V_3 ) {
V_35 = F_16 ( V_2 -> V_3 , V_4 ) ;
V_36 = F_17 ( V_5 , V_2 -> V_5 + V_2 -> V_26 , V_35 ) ;
if ( V_36 )
goto V_40;
V_2 -> V_3 -= V_35 ;
V_2 -> V_26 += V_35 ;
V_4 -= V_35 ;
V_5 += V_35 ;
V_34 += V_35 ;
if ( ! V_2 -> V_3 )
V_2 -> V_24 ++ ;
if ( ! V_4 )
goto V_38;
}
V_23 = V_2 -> V_24 ;
V_13 = V_2 -> V_12 -> V_27 ( V_2 , & V_23 ) ;
while ( 1 ) {
V_36 = F_9 ( V_13 ) ;
if ( ! V_13 || F_10 ( V_13 ) )
break;
V_36 = V_2 -> V_12 -> V_28 ( V_2 , V_13 ) ;
if ( V_36 < 0 )
break;
if ( F_11 ( V_36 ) )
V_2 -> V_3 = 0 ;
if ( F_11 ( ! V_2 -> V_3 ) ) {
V_13 = V_2 -> V_12 -> V_30 ( V_2 , V_13 , & V_23 ) ;
V_2 -> V_24 = V_23 ;
continue;
}
if ( V_2 -> V_3 < V_2 -> V_4 )
goto V_41;
V_2 -> V_12 -> V_31 ( V_2 , V_13 ) ;
F_13 ( V_2 -> V_5 ) ;
V_2 -> V_3 = 0 ;
V_2 -> V_5 = F_2 ( V_2 -> V_4 <<= 1 ) ;
if ( ! V_2 -> V_5 )
goto V_39;
V_2 -> V_25 = 0 ;
V_23 = V_2 -> V_24 ;
V_13 = V_2 -> V_12 -> V_27 ( V_2 , & V_23 ) ;
}
V_2 -> V_12 -> V_31 ( V_2 , V_13 ) ;
V_2 -> V_3 = 0 ;
goto V_38;
V_41:
while ( V_2 -> V_3 < V_4 ) {
T_4 V_42 = V_2 -> V_3 ;
T_1 V_30 = V_23 ;
V_13 = V_2 -> V_12 -> V_30 ( V_2 , V_13 , & V_30 ) ;
if ( ! V_13 || F_10 ( V_13 ) ) {
V_36 = F_9 ( V_13 ) ;
break;
}
V_36 = V_2 -> V_12 -> V_28 ( V_2 , V_13 ) ;
if ( F_12 ( V_2 ) || V_36 ) {
V_2 -> V_3 = V_42 ;
if ( F_18 ( V_36 <= 0 ) )
break;
}
V_23 = V_30 ;
}
V_2 -> V_12 -> V_31 ( V_2 , V_13 ) ;
V_35 = F_16 ( V_2 -> V_3 , V_4 ) ;
V_36 = F_17 ( V_5 , V_2 -> V_5 , V_35 ) ;
if ( V_36 )
goto V_40;
V_34 += V_35 ;
V_2 -> V_3 -= V_35 ;
if ( V_2 -> V_3 )
V_2 -> V_26 = V_35 ;
else
V_23 ++ ;
V_2 -> V_24 = V_23 ;
V_38:
if ( ! V_34 )
V_34 = V_36 ;
else {
* V_33 += V_34 ;
V_2 -> V_37 += V_34 ;
}
V_10 -> V_19 = V_2 -> V_25 ;
F_19 ( & V_2 -> V_16 ) ;
return V_34 ;
V_39:
V_36 = - V_15 ;
goto V_38;
V_40:
V_36 = - V_43 ;
goto V_38;
}
T_1 F_20 ( struct V_10 * V_10 , T_1 V_22 , int V_44 )
{
struct V_1 * V_2 = V_10 -> V_14 ;
T_1 V_45 = - V_46 ;
F_15 ( & V_2 -> V_16 ) ;
V_2 -> V_25 = V_10 -> V_19 ;
switch ( V_44 ) {
case V_47 :
V_22 += V_10 -> V_48 ;
case V_49 :
if ( V_22 < 0 )
break;
V_45 = V_22 ;
if ( V_22 != V_2 -> V_37 ) {
while ( ( V_45 = F_8 ( V_2 , V_22 ) ) == - V_32 )
;
if ( V_45 ) {
V_10 -> V_48 = 0 ;
V_2 -> V_37 = 0 ;
V_2 -> V_25 = 0 ;
V_2 -> V_24 = 0 ;
V_2 -> V_3 = 0 ;
} else {
V_2 -> V_37 = V_22 ;
V_45 = V_10 -> V_48 = V_22 ;
}
} else {
V_10 -> V_48 = V_22 ;
}
}
V_10 -> V_19 = V_2 -> V_25 ;
F_19 ( & V_2 -> V_16 ) ;
return V_45 ;
}
int F_21 ( struct V_50 * V_50 , struct V_10 * V_10 )
{
struct V_1 * V_2 = V_10 -> V_14 ;
F_13 ( V_2 -> V_5 ) ;
F_22 ( V_2 ) ;
return 0 ;
}
int F_23 ( struct V_1 * V_2 , const char * V_51 , const char * V_52 )
{
char * V_53 = V_2 -> V_5 + V_2 -> V_4 ;
char * V_13 ;
char V_54 ;
for ( V_13 = V_2 -> V_5 + V_2 -> V_3 ; ( V_54 = * V_51 ) != '\0' && V_13 < V_53 ; V_51 ++ ) {
if ( ! strchr ( V_52 , V_54 ) ) {
* V_13 ++ = V_54 ;
continue;
}
if ( V_13 + 3 < V_53 ) {
* V_13 ++ = '\\' ;
* V_13 ++ = '0' + ( ( V_54 & 0300 ) >> 6 ) ;
* V_13 ++ = '0' + ( ( V_54 & 070 ) >> 3 ) ;
* V_13 ++ = '0' + ( V_54 & 07 ) ;
continue;
}
F_1 ( V_2 ) ;
return - 1 ;
}
V_2 -> V_3 = V_13 - V_2 -> V_5 ;
return 0 ;
}
int F_24 ( struct V_1 * V_2 , const char * V_55 , T_5 args )
{
int V_56 ;
if ( V_2 -> V_3 < V_2 -> V_4 ) {
V_56 = vsnprintf ( V_2 -> V_5 + V_2 -> V_3 , V_2 -> V_4 - V_2 -> V_3 , V_55 , args ) ;
if ( V_2 -> V_3 + V_56 < V_2 -> V_4 ) {
V_2 -> V_3 += V_56 ;
return 0 ;
}
}
F_1 ( V_2 ) ;
return - 1 ;
}
int F_25 ( struct V_1 * V_2 , const char * V_55 , ... )
{
int V_57 ;
T_5 args ;
va_start ( args , V_55 ) ;
V_57 = F_24 ( V_2 , V_55 , args ) ;
va_end ( args ) ;
return V_57 ;
}
char * F_26 ( char * V_51 , const char * V_13 , const char * V_52 )
{
while ( V_51 <= V_13 ) {
char V_54 = * V_13 ++ ;
if ( ! V_54 ) {
return V_51 ;
} else if ( ! strchr ( V_52 , V_54 ) ) {
* V_51 ++ = V_54 ;
} else if ( V_51 + 4 > V_13 ) {
break;
} else {
* V_51 ++ = '\\' ;
* V_51 ++ = '0' + ( ( V_54 & 0300 ) >> 6 ) ;
* V_51 ++ = '0' + ( ( V_54 & 070 ) >> 3 ) ;
* V_51 ++ = '0' + ( V_54 & 07 ) ;
}
}
return NULL ;
}
int F_27 ( struct V_1 * V_2 , const struct V_58 * V_58 , const char * V_52 )
{
char * V_5 ;
T_4 V_4 = F_28 ( V_2 , & V_5 ) ;
int V_59 = - 1 ;
if ( V_4 ) {
char * V_13 = F_29 ( V_58 , V_5 , V_4 ) ;
if ( ! F_10 ( V_13 ) ) {
char * V_53 = F_26 ( V_5 , V_13 , V_52 ) ;
if ( V_53 )
V_59 = V_53 - V_5 ;
}
}
F_30 ( V_2 , V_59 ) ;
return V_59 ;
}
int F_31 ( struct V_1 * V_2 , const struct V_58 * V_58 ,
const struct V_58 * V_60 , const char * V_52 )
{
char * V_5 ;
T_4 V_4 = F_28 ( V_2 , & V_5 ) ;
int V_59 = - V_61 ;
if ( V_4 ) {
char * V_13 ;
V_13 = F_32 ( V_58 , V_60 , V_5 , V_4 ) ;
if ( ! V_13 )
return V_62 ;
V_59 = F_9 ( V_13 ) ;
if ( ! F_10 ( V_13 ) ) {
char * V_53 = F_26 ( V_5 , V_13 , V_52 ) ;
if ( V_53 )
V_59 = V_53 - V_5 ;
else
V_59 = - V_61 ;
}
}
F_30 ( V_2 , V_59 ) ;
return V_59 < 0 && V_59 != - V_61 ? V_59 : 0 ;
}
int F_33 ( struct V_1 * V_2 , struct V_63 * V_63 , const char * V_52 )
{
char * V_5 ;
T_4 V_4 = F_28 ( V_2 , & V_5 ) ;
int V_59 = - 1 ;
if ( V_4 ) {
char * V_13 = F_34 ( V_63 , V_5 , V_4 ) ;
if ( ! F_10 ( V_13 ) ) {
char * V_53 = F_26 ( V_5 , V_13 , V_52 ) ;
if ( V_53 )
V_59 = V_53 - V_5 ;
}
}
F_30 ( V_2 , V_59 ) ;
return V_59 ;
}
static void * F_35 ( struct V_1 * V_13 , T_1 * V_23 )
{
return NULL + ( * V_23 == 0 ) ;
}
static void * F_36 ( struct V_1 * V_13 , void * V_64 , T_1 * V_23 )
{
++ * V_23 ;
return NULL ;
}
static void F_37 ( struct V_1 * V_13 , void * V_64 )
{
}
int F_38 ( struct V_10 * V_10 , int (* V_28)( struct V_1 * , void * ) ,
void * V_65 )
{
struct V_11 * V_12 = F_3 ( sizeof( * V_12 ) , V_6 ) ;
int V_59 = - V_15 ;
if ( V_12 ) {
V_12 -> V_27 = F_35 ;
V_12 -> V_30 = F_36 ;
V_12 -> V_31 = F_37 ;
V_12 -> V_28 = V_28 ;
V_59 = F_5 ( V_10 , V_12 ) ;
if ( ! V_59 )
( (struct V_1 * ) V_10 -> V_14 ) -> V_66 = V_65 ;
else
F_22 ( V_12 ) ;
}
return V_59 ;
}
int F_39 ( struct V_10 * V_10 , int (* V_28)( struct V_1 * , void * ) ,
void * V_65 , T_4 V_4 )
{
char * V_5 = F_2 ( V_4 ) ;
int V_57 ;
if ( ! V_5 )
return - V_15 ;
V_57 = F_38 ( V_10 , V_28 , V_65 ) ;
if ( V_57 ) {
F_13 ( V_5 ) ;
return V_57 ;
}
( (struct V_1 * ) V_10 -> V_14 ) -> V_5 = V_5 ;
( (struct V_1 * ) V_10 -> V_14 ) -> V_4 = V_4 ;
return 0 ;
}
int F_40 ( struct V_50 * V_50 , struct V_10 * V_10 )
{
const struct V_11 * V_12 = ( (struct V_1 * ) V_10 -> V_14 ) -> V_12 ;
int V_59 = F_21 ( V_50 , V_10 ) ;
F_22 ( V_12 ) ;
return V_59 ;
}
int F_41 ( struct V_50 * V_50 , struct V_10 * V_10 )
{
struct V_1 * V_67 = V_10 -> V_14 ;
F_22 ( V_67 -> V_66 ) ;
V_67 -> V_66 = NULL ;
return F_21 ( V_50 , V_10 ) ;
}
void * F_42 ( struct V_10 * V_55 , const struct V_11 * V_68 ,
int V_69 )
{
int V_70 ;
void * V_66 ;
struct V_1 * V_67 ;
V_66 = F_43 ( V_69 , V_6 ) ;
if ( V_66 == NULL )
goto V_71;
V_70 = F_5 ( V_55 , V_68 ) ;
if ( V_70 < 0 )
goto V_72;
V_67 = V_55 -> V_14 ;
V_67 -> V_66 = V_66 ;
return V_66 ;
V_72:
F_22 ( V_66 ) ;
V_71:
return NULL ;
}
int F_44 ( struct V_10 * V_73 , const struct V_11 * V_68 ,
int V_69 )
{
return F_42 ( V_73 , V_68 , V_69 ) ? 0 : - V_15 ;
}
int F_45 ( struct V_1 * V_2 , char V_54 )
{
if ( V_2 -> V_3 < V_2 -> V_4 ) {
V_2 -> V_5 [ V_2 -> V_3 ++ ] = V_54 ;
return 0 ;
}
return - 1 ;
}
int F_46 ( struct V_1 * V_2 , const char * V_51 )
{
int V_56 = strlen ( V_51 ) ;
if ( V_2 -> V_3 + V_56 < V_2 -> V_4 ) {
memcpy ( V_2 -> V_5 + V_2 -> V_3 , V_51 , V_56 ) ;
V_2 -> V_3 += V_56 ;
return 0 ;
}
F_1 ( V_2 ) ;
return - 1 ;
}
int F_47 ( struct V_1 * V_2 , char V_74 ,
unsigned long long V_75 )
{
int V_56 ;
if ( V_2 -> V_3 + 2 >= V_2 -> V_4 )
goto V_76;
if ( V_74 )
V_2 -> V_5 [ V_2 -> V_3 ++ ] = V_74 ;
if ( V_75 < 10 ) {
V_2 -> V_5 [ V_2 -> V_3 ++ ] = V_75 + '0' ;
return 0 ;
}
V_56 = F_48 ( V_2 -> V_5 + V_2 -> V_3 , V_2 -> V_4 - V_2 -> V_3 , V_75 ) ;
if ( ! V_56 )
goto V_76;
V_2 -> V_3 += V_56 ;
return 0 ;
V_76:
F_1 ( V_2 ) ;
return - 1 ;
}
int F_49 ( struct V_1 * V_2 , char V_74 ,
long long V_75 )
{
if ( V_75 < 0 ) {
if ( V_2 -> V_3 + 3 >= V_2 -> V_4 ) {
F_1 ( V_2 ) ;
return - 1 ;
}
if ( V_74 )
V_2 -> V_5 [ V_2 -> V_3 ++ ] = V_74 ;
V_75 = - V_75 ;
V_74 = '-' ;
}
return F_47 ( V_2 , V_74 , V_75 ) ;
}
int F_50 ( struct V_1 * V_67 , const void * V_65 , T_4 V_56 )
{
if ( V_67 -> V_3 + V_56 < V_67 -> V_4 ) {
memcpy ( V_67 -> V_5 + V_67 -> V_3 , V_65 , V_56 ) ;
V_67 -> V_3 += V_56 ;
return 0 ;
}
F_1 ( V_67 ) ;
return - 1 ;
}
void F_51 ( struct V_1 * V_2 , char V_54 )
{
int V_4 = V_2 -> V_77 - V_2 -> V_3 ;
if ( V_4 > 0 )
F_25 ( V_2 , L_1 , V_4 , L_2 ) ;
if ( V_54 )
F_45 ( V_2 , V_54 ) ;
}
struct V_78 * F_52 ( struct V_78 * V_79 , T_1 V_23 )
{
struct V_78 * V_80 ;
F_53 (lh, head)
if ( V_23 -- == 0 )
return V_80 ;
return NULL ;
}
struct V_78 * F_54 ( struct V_78 * V_79 , T_1 V_23 )
{
if ( ! V_23 )
return V_79 ;
return F_52 ( V_79 , V_23 - 1 ) ;
}
struct V_78 * F_55 ( void * V_64 , struct V_78 * V_79 , T_1 * V_33 )
{
struct V_78 * V_80 ;
V_80 = ( (struct V_78 * ) V_64 ) -> V_30 ;
++ * V_33 ;
return V_80 == V_79 ? NULL : V_80 ;
}
struct V_81 * F_56 ( struct V_82 * V_79 , T_1 V_23 )
{
struct V_81 * V_83 ;
F_57 (node, head)
if ( V_23 -- == 0 )
return V_83 ;
return NULL ;
}
struct V_81 * F_58 ( struct V_82 * V_79 , T_1 V_23 )
{
if ( ! V_23 )
return V_84 ;
return F_56 ( V_79 , V_23 - 1 ) ;
}
struct V_81 * F_59 ( void * V_64 , struct V_82 * V_79 ,
T_1 * V_33 )
{
struct V_81 * V_83 = V_64 ;
++ * V_33 ;
if ( V_64 == V_84 )
return V_79 -> V_85 ;
else
return V_83 -> V_30 ;
}
struct V_81 * F_60 ( struct V_82 * V_79 ,
T_1 V_23 )
{
struct V_81 * V_83 ;
F_61 (node, head)
if ( V_23 -- == 0 )
return V_83 ;
return NULL ;
}
struct V_81 * F_62 ( struct V_82 * V_79 ,
T_1 V_23 )
{
if ( ! V_23 )
return V_84 ;
return F_60 ( V_79 , V_23 - 1 ) ;
}
struct V_81 * F_63 ( void * V_64 ,
struct V_82 * V_79 ,
T_1 * V_33 )
{
struct V_81 * V_83 = V_64 ;
++ * V_33 ;
if ( V_64 == V_84 )
return F_64 ( V_79 -> V_85 ) ;
else
return F_64 ( V_83 -> V_30 ) ;
}
struct V_81 *
F_65 ( struct V_82 T_6 * V_79 , int * V_86 , T_1 V_23 )
{
struct V_81 * V_83 ;
F_66 (*cpu) {
F_57 (node, per_cpu_ptr(head, *cpu)) {
if ( V_23 -- == 0 )
return V_83 ;
}
}
return NULL ;
}
struct V_81 *
F_67 ( void * V_64 , struct V_82 T_6 * V_79 ,
int * V_86 , T_1 * V_23 )
{
struct V_81 * V_83 = V_64 ;
++ * V_23 ;
if ( V_83 -> V_30 )
return V_83 -> V_30 ;
for ( * V_86 = F_68 ( * V_86 , V_87 ) ; * V_86 < V_88 ;
* V_86 = F_68 ( * V_86 , V_87 ) ) {
struct V_82 * V_89 = F_69 ( V_79 , * V_86 ) ;
if ( ! F_70 ( V_89 ) )
return V_89 -> V_85 ;
}
return NULL ;
}
