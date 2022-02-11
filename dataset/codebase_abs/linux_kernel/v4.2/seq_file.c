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
struct V_1 * V_13 ;
F_6 ( V_10 -> V_14 ) ;
V_13 = F_7 ( sizeof( * V_13 ) , V_6 ) ;
if ( ! V_13 )
return - V_15 ;
V_10 -> V_14 = V_13 ;
F_8 ( & V_13 -> V_16 ) ;
V_13 -> V_12 = V_12 ;
#ifdef F_9
V_13 -> V_17 = V_10 -> V_18 -> V_17 ;
#endif
V_10 -> V_19 = 0 ;
V_10 -> V_20 &= ~ V_21 ;
return 0 ;
}
static int F_10 ( struct V_1 * V_2 , T_1 V_22 )
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
error = F_11 ( V_13 ) ;
if ( F_12 ( V_13 ) )
break;
error = V_2 -> V_12 -> V_28 ( V_2 , V_13 ) ;
if ( error < 0 )
break;
if ( F_13 ( error ) ) {
error = 0 ;
V_2 -> V_3 = 0 ;
}
if ( F_14 ( V_2 ) )
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
F_15 ( V_2 -> V_5 ) ;
V_2 -> V_3 = 0 ;
V_2 -> V_5 = F_2 ( V_2 -> V_4 <<= 1 ) ;
return ! V_2 -> V_5 ? - V_15 : - V_32 ;
}
T_2 F_16 ( struct V_10 * V_10 , char T_3 * V_5 , T_4 V_4 , T_1 * V_33 )
{
struct V_1 * V_2 = V_10 -> V_14 ;
T_4 V_34 = 0 ;
T_1 V_23 ;
T_4 V_35 ;
void * V_13 ;
int V_36 = 0 ;
F_17 ( & V_2 -> V_16 ) ;
V_2 -> V_25 = V_10 -> V_19 ;
if ( F_13 ( * V_33 != V_2 -> V_37 ) ) {
while ( ( V_36 = F_10 ( V_2 , * V_33 ) ) == - V_32 )
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
V_35 = F_18 ( V_2 -> V_3 , V_4 ) ;
V_36 = F_19 ( V_5 , V_2 -> V_5 + V_2 -> V_26 , V_35 ) ;
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
V_36 = F_11 ( V_13 ) ;
if ( ! V_13 || F_12 ( V_13 ) )
break;
V_36 = V_2 -> V_12 -> V_28 ( V_2 , V_13 ) ;
if ( V_36 < 0 )
break;
if ( F_13 ( V_36 ) )
V_2 -> V_3 = 0 ;
if ( F_13 ( ! V_2 -> V_3 ) ) {
V_13 = V_2 -> V_12 -> V_30 ( V_2 , V_13 , & V_23 ) ;
V_2 -> V_24 = V_23 ;
continue;
}
if ( V_2 -> V_3 < V_2 -> V_4 )
goto V_41;
V_2 -> V_12 -> V_31 ( V_2 , V_13 ) ;
F_15 ( V_2 -> V_5 ) ;
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
if ( ! V_13 || F_12 ( V_13 ) ) {
V_36 = F_11 ( V_13 ) ;
break;
}
V_36 = V_2 -> V_12 -> V_28 ( V_2 , V_13 ) ;
if ( F_14 ( V_2 ) || V_36 ) {
V_2 -> V_3 = V_42 ;
if ( F_20 ( V_36 <= 0 ) )
break;
}
V_23 = V_30 ;
}
V_2 -> V_12 -> V_31 ( V_2 , V_13 ) ;
V_35 = F_18 ( V_2 -> V_3 , V_4 ) ;
V_36 = F_19 ( V_5 , V_2 -> V_5 , V_35 ) ;
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
F_21 ( & V_2 -> V_16 ) ;
return V_34 ;
V_39:
V_36 = - V_15 ;
goto V_38;
V_40:
V_36 = - V_43 ;
goto V_38;
}
T_1 F_22 ( struct V_10 * V_10 , T_1 V_22 , int V_44 )
{
struct V_1 * V_2 = V_10 -> V_14 ;
T_1 V_45 = - V_46 ;
F_17 ( & V_2 -> V_16 ) ;
V_2 -> V_25 = V_10 -> V_19 ;
switch ( V_44 ) {
case V_47 :
V_22 += V_10 -> V_48 ;
case V_49 :
if ( V_22 < 0 )
break;
V_45 = V_22 ;
if ( V_22 != V_2 -> V_37 ) {
while ( ( V_45 = F_10 ( V_2 , V_22 ) ) == - V_32 )
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
F_21 ( & V_2 -> V_16 ) ;
return V_45 ;
}
int F_23 ( struct V_50 * V_50 , struct V_10 * V_10 )
{
struct V_1 * V_2 = V_10 -> V_14 ;
F_15 ( V_2 -> V_5 ) ;
F_24 ( V_2 ) ;
return 0 ;
}
int F_25 ( struct V_1 * V_2 , const char * V_51 , const char * V_52 )
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
int F_26 ( struct V_1 * V_2 , const char * V_55 , T_5 args )
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
int F_27 ( struct V_1 * V_2 , const char * V_55 , ... )
{
int V_57 ;
T_5 args ;
va_start ( args , V_55 ) ;
V_57 = F_26 ( V_2 , V_55 , args ) ;
va_end ( args ) ;
return V_57 ;
}
char * F_28 ( char * V_51 , const char * V_13 , const char * V_52 )
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
int F_29 ( struct V_1 * V_2 , const struct V_58 * V_58 , const char * V_52 )
{
char * V_5 ;
T_4 V_4 = F_30 ( V_2 , & V_5 ) ;
int V_59 = - 1 ;
if ( V_4 ) {
char * V_13 = F_31 ( V_58 , V_5 , V_4 ) ;
if ( ! F_12 ( V_13 ) ) {
char * V_53 = F_28 ( V_5 , V_13 , V_52 ) ;
if ( V_53 )
V_59 = V_53 - V_5 ;
}
}
F_32 ( V_2 , V_59 ) ;
return V_59 ;
}
int F_33 ( struct V_1 * V_2 , struct V_10 * V_10 , const char * V_52 )
{
return F_29 ( V_2 , & V_10 -> V_60 , V_52 ) ;
}
int F_34 ( struct V_1 * V_2 , const struct V_58 * V_58 ,
const struct V_58 * V_61 , const char * V_52 )
{
char * V_5 ;
T_4 V_4 = F_30 ( V_2 , & V_5 ) ;
int V_59 = - V_62 ;
if ( V_4 ) {
char * V_13 ;
V_13 = F_35 ( V_58 , V_61 , V_5 , V_4 ) ;
if ( ! V_13 )
return V_63 ;
V_59 = F_11 ( V_13 ) ;
if ( ! F_12 ( V_13 ) ) {
char * V_53 = F_28 ( V_5 , V_13 , V_52 ) ;
if ( V_53 )
V_59 = V_53 - V_5 ;
else
V_59 = - V_62 ;
}
}
F_32 ( V_2 , V_59 ) ;
return V_59 < 0 && V_59 != - V_62 ? V_59 : 0 ;
}
int F_36 ( struct V_1 * V_2 , struct V_64 * V_64 , const char * V_52 )
{
char * V_5 ;
T_4 V_4 = F_30 ( V_2 , & V_5 ) ;
int V_59 = - 1 ;
if ( V_4 ) {
char * V_13 = F_37 ( V_64 , V_5 , V_4 ) ;
if ( ! F_12 ( V_13 ) ) {
char * V_53 = F_28 ( V_5 , V_13 , V_52 ) ;
if ( V_53 )
V_59 = V_53 - V_5 ;
}
}
F_32 ( V_2 , V_59 ) ;
return V_59 ;
}
static void * F_38 ( struct V_1 * V_13 , T_1 * V_23 )
{
return NULL + ( * V_23 == 0 ) ;
}
static void * F_39 ( struct V_1 * V_13 , void * V_65 , T_1 * V_23 )
{
++ * V_23 ;
return NULL ;
}
static void F_40 ( struct V_1 * V_13 , void * V_65 )
{
}
int F_41 ( struct V_10 * V_10 , int (* V_28)( struct V_1 * , void * ) ,
void * V_66 )
{
struct V_11 * V_12 = F_3 ( sizeof( * V_12 ) , V_6 ) ;
int V_59 = - V_15 ;
if ( V_12 ) {
V_12 -> V_27 = F_38 ;
V_12 -> V_30 = F_39 ;
V_12 -> V_31 = F_40 ;
V_12 -> V_28 = V_28 ;
V_59 = F_5 ( V_10 , V_12 ) ;
if ( ! V_59 )
( (struct V_1 * ) V_10 -> V_14 ) -> V_67 = V_66 ;
else
F_24 ( V_12 ) ;
}
return V_59 ;
}
int F_42 ( struct V_10 * V_10 , int (* V_28)( struct V_1 * , void * ) ,
void * V_66 , T_4 V_4 )
{
char * V_5 = F_2 ( V_4 ) ;
int V_57 ;
if ( ! V_5 )
return - V_15 ;
V_57 = F_41 ( V_10 , V_28 , V_66 ) ;
if ( V_57 ) {
F_15 ( V_5 ) ;
return V_57 ;
}
( (struct V_1 * ) V_10 -> V_14 ) -> V_5 = V_5 ;
( (struct V_1 * ) V_10 -> V_14 ) -> V_4 = V_4 ;
return 0 ;
}
int F_43 ( struct V_50 * V_50 , struct V_10 * V_10 )
{
const struct V_11 * V_12 = ( (struct V_1 * ) V_10 -> V_14 ) -> V_12 ;
int V_59 = F_23 ( V_50 , V_10 ) ;
F_24 ( V_12 ) ;
return V_59 ;
}
int F_44 ( struct V_50 * V_50 , struct V_10 * V_10 )
{
struct V_1 * V_68 = V_10 -> V_14 ;
F_24 ( V_68 -> V_67 ) ;
V_68 -> V_67 = NULL ;
return F_23 ( V_50 , V_10 ) ;
}
void * F_45 ( struct V_10 * V_55 , const struct V_11 * V_69 ,
int V_70 )
{
int V_71 ;
void * V_67 ;
struct V_1 * V_68 ;
V_67 = F_7 ( V_70 , V_6 ) ;
if ( V_67 == NULL )
goto V_72;
V_71 = F_5 ( V_55 , V_69 ) ;
if ( V_71 < 0 )
goto V_73;
V_68 = V_55 -> V_14 ;
V_68 -> V_67 = V_67 ;
return V_67 ;
V_73:
F_24 ( V_67 ) ;
V_72:
return NULL ;
}
int F_46 ( struct V_10 * V_74 , const struct V_11 * V_69 ,
int V_70 )
{
return F_45 ( V_74 , V_69 , V_70 ) ? 0 : - V_15 ;
}
int F_47 ( struct V_1 * V_2 , char V_54 )
{
if ( V_2 -> V_3 < V_2 -> V_4 ) {
V_2 -> V_5 [ V_2 -> V_3 ++ ] = V_54 ;
return 0 ;
}
return - 1 ;
}
int F_48 ( struct V_1 * V_2 , const char * V_51 )
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
int F_49 ( struct V_1 * V_2 , char V_75 ,
unsigned long long V_76 )
{
int V_56 ;
if ( V_2 -> V_3 + 2 >= V_2 -> V_4 )
goto V_77;
if ( V_75 )
V_2 -> V_5 [ V_2 -> V_3 ++ ] = V_75 ;
if ( V_76 < 10 ) {
V_2 -> V_5 [ V_2 -> V_3 ++ ] = V_76 + '0' ;
return 0 ;
}
V_56 = F_50 ( V_2 -> V_5 + V_2 -> V_3 , V_2 -> V_4 - V_2 -> V_3 , V_76 ) ;
if ( ! V_56 )
goto V_77;
V_2 -> V_3 += V_56 ;
return 0 ;
V_77:
F_1 ( V_2 ) ;
return - 1 ;
}
int F_51 ( struct V_1 * V_2 , char V_75 ,
long long V_76 )
{
if ( V_76 < 0 ) {
if ( V_2 -> V_3 + 3 >= V_2 -> V_4 ) {
F_1 ( V_2 ) ;
return - 1 ;
}
if ( V_75 )
V_2 -> V_5 [ V_2 -> V_3 ++ ] = V_75 ;
V_76 = - V_76 ;
V_75 = '-' ;
}
return F_49 ( V_2 , V_75 , V_76 ) ;
}
int F_52 ( struct V_1 * V_68 , const void * V_66 , T_4 V_56 )
{
if ( V_68 -> V_3 + V_56 < V_68 -> V_4 ) {
memcpy ( V_68 -> V_5 + V_68 -> V_3 , V_66 , V_56 ) ;
V_68 -> V_3 += V_56 ;
return 0 ;
}
F_1 ( V_68 ) ;
return - 1 ;
}
void F_53 ( struct V_1 * V_2 , char V_54 )
{
int V_4 = V_2 -> V_78 - V_2 -> V_3 ;
if ( V_4 > 0 )
F_27 ( V_2 , L_1 , V_4 , L_2 ) ;
if ( V_54 )
F_47 ( V_2 , V_54 ) ;
}
struct V_79 * F_54 ( struct V_79 * V_80 , T_1 V_23 )
{
struct V_79 * V_81 ;
F_55 (lh, head)
if ( V_23 -- == 0 )
return V_81 ;
return NULL ;
}
struct V_79 * F_56 ( struct V_79 * V_80 , T_1 V_23 )
{
if ( ! V_23 )
return V_80 ;
return F_54 ( V_80 , V_23 - 1 ) ;
}
struct V_79 * F_57 ( void * V_65 , struct V_79 * V_80 , T_1 * V_33 )
{
struct V_79 * V_81 ;
V_81 = ( (struct V_79 * ) V_65 ) -> V_30 ;
++ * V_33 ;
return V_81 == V_80 ? NULL : V_81 ;
}
struct V_82 * F_58 ( struct V_83 * V_80 , T_1 V_23 )
{
struct V_82 * V_84 ;
F_59 (node, head)
if ( V_23 -- == 0 )
return V_84 ;
return NULL ;
}
struct V_82 * F_60 ( struct V_83 * V_80 , T_1 V_23 )
{
if ( ! V_23 )
return V_85 ;
return F_58 ( V_80 , V_23 - 1 ) ;
}
struct V_82 * F_61 ( void * V_65 , struct V_83 * V_80 ,
T_1 * V_33 )
{
struct V_82 * V_84 = V_65 ;
++ * V_33 ;
if ( V_65 == V_85 )
return V_80 -> V_86 ;
else
return V_84 -> V_30 ;
}
struct V_82 * F_62 ( struct V_83 * V_80 ,
T_1 V_23 )
{
struct V_82 * V_84 ;
F_63 (node, head)
if ( V_23 -- == 0 )
return V_84 ;
return NULL ;
}
struct V_82 * F_64 ( struct V_83 * V_80 ,
T_1 V_23 )
{
if ( ! V_23 )
return V_85 ;
return F_62 ( V_80 , V_23 - 1 ) ;
}
struct V_82 * F_65 ( void * V_65 ,
struct V_83 * V_80 ,
T_1 * V_33 )
{
struct V_82 * V_84 = V_65 ;
++ * V_33 ;
if ( V_65 == V_85 )
return F_66 ( V_80 -> V_86 ) ;
else
return F_66 ( V_84 -> V_30 ) ;
}
struct V_82 *
F_67 ( struct V_83 T_6 * V_80 , int * V_87 , T_1 V_23 )
{
struct V_82 * V_84 ;
F_68 (*cpu) {
F_59 (node, per_cpu_ptr(head, *cpu)) {
if ( V_23 -- == 0 )
return V_84 ;
}
}
return NULL ;
}
struct V_82 *
F_69 ( void * V_65 , struct V_83 T_6 * V_80 ,
int * V_87 , T_1 * V_23 )
{
struct V_82 * V_84 = V_65 ;
++ * V_23 ;
if ( V_84 -> V_30 )
return V_84 -> V_30 ;
for ( * V_87 = F_70 ( * V_87 , V_88 ) ; * V_87 < V_89 ;
* V_87 = F_70 ( * V_87 , V_88 ) ) {
struct V_83 * V_90 = F_71 ( V_80 , * V_87 ) ;
if ( ! F_72 ( V_90 ) )
return V_90 -> V_86 ;
}
return NULL ;
}
