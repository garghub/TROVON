static bool F_1 ( struct V_1 * V_2 )
{
return V_2 -> V_3 == V_2 -> V_4 ;
}
static void F_2 ( struct V_1 * V_2 )
{
V_2 -> V_3 = V_2 -> V_4 ;
}
int F_3 ( struct V_5 * V_5 , const struct V_6 * V_7 )
{
struct V_1 * V_8 = V_5 -> V_9 ;
if ( ! V_8 ) {
V_8 = F_4 ( sizeof( * V_8 ) , V_10 ) ;
if ( ! V_8 )
return - V_11 ;
V_5 -> V_9 = V_8 ;
}
memset ( V_8 , 0 , sizeof( * V_8 ) ) ;
F_5 ( & V_8 -> V_12 ) ;
V_8 -> V_7 = V_7 ;
#ifdef F_6
V_8 -> V_13 = V_5 -> V_14 -> V_13 ;
#endif
V_5 -> V_15 = 0 ;
V_5 -> V_16 &= ~ V_17 ;
return 0 ;
}
static int F_7 ( struct V_1 * V_2 , T_1 V_18 )
{
T_1 V_19 = 0 , V_20 ;
int error = 0 ;
void * V_8 ;
V_2 -> V_21 = 0 ;
V_20 = 0 ;
V_2 -> V_3 = V_2 -> V_22 = 0 ;
if ( ! V_18 ) {
V_2 -> V_20 = V_20 ;
return 0 ;
}
if ( ! V_2 -> V_23 ) {
V_2 -> V_23 = F_4 ( V_2 -> V_4 = V_24 , V_10 ) ;
if ( ! V_2 -> V_23 )
return - V_11 ;
}
V_8 = V_2 -> V_7 -> V_25 ( V_2 , & V_20 ) ;
while ( V_8 ) {
error = F_8 ( V_8 ) ;
if ( F_9 ( V_8 ) )
break;
error = V_2 -> V_7 -> V_26 ( V_2 , V_8 ) ;
if ( error < 0 )
break;
if ( F_10 ( error ) ) {
error = 0 ;
V_2 -> V_3 = 0 ;
}
if ( F_1 ( V_2 ) )
goto V_27;
if ( V_19 + V_2 -> V_3 > V_18 ) {
V_2 -> V_22 = V_18 - V_19 ;
V_2 -> V_3 -= V_2 -> V_22 ;
V_2 -> V_20 = V_20 ;
break;
}
V_19 += V_2 -> V_3 ;
V_2 -> V_3 = 0 ;
if ( V_19 == V_18 ) {
V_20 ++ ;
V_2 -> V_20 = V_20 ;
break;
}
V_8 = V_2 -> V_7 -> V_28 ( V_2 , V_8 , & V_20 ) ;
}
V_2 -> V_7 -> V_29 ( V_2 , V_8 ) ;
V_2 -> V_20 = V_20 ;
return error ;
V_27:
V_2 -> V_7 -> V_29 ( V_2 , V_8 ) ;
F_11 ( V_2 -> V_23 ) ;
V_2 -> V_23 = F_4 ( V_2 -> V_4 <<= 1 , V_10 ) ;
return ! V_2 -> V_23 ? - V_11 : - V_30 ;
}
T_2 F_12 ( struct V_5 * V_5 , char T_3 * V_23 , T_4 V_4 , T_1 * V_31 )
{
struct V_1 * V_2 = V_5 -> V_9 ;
T_4 V_32 = 0 ;
T_1 V_19 ;
T_4 V_33 ;
void * V_8 ;
int V_34 = 0 ;
F_13 ( & V_2 -> V_12 ) ;
V_2 -> V_21 = V_5 -> V_15 ;
if ( F_10 ( * V_31 != V_2 -> V_35 ) ) {
while ( ( V_34 = F_7 ( V_2 , * V_31 ) ) == - V_30 )
;
if ( V_34 ) {
V_2 -> V_35 = 0 ;
V_2 -> V_21 = 0 ;
V_2 -> V_20 = 0 ;
V_2 -> V_3 = 0 ;
goto V_36;
} else {
V_2 -> V_35 = * V_31 ;
}
}
if ( ! V_2 -> V_23 ) {
V_2 -> V_23 = F_4 ( V_2 -> V_4 = V_24 , V_10 ) ;
if ( ! V_2 -> V_23 )
goto V_37;
}
if ( V_2 -> V_3 ) {
V_33 = F_14 ( V_2 -> V_3 , V_4 ) ;
V_34 = F_15 ( V_23 , V_2 -> V_23 + V_2 -> V_22 , V_33 ) ;
if ( V_34 )
goto V_38;
V_2 -> V_3 -= V_33 ;
V_2 -> V_22 += V_33 ;
V_4 -= V_33 ;
V_23 += V_33 ;
V_32 += V_33 ;
if ( ! V_2 -> V_3 )
V_2 -> V_20 ++ ;
if ( ! V_4 )
goto V_36;
}
V_19 = V_2 -> V_20 ;
V_8 = V_2 -> V_7 -> V_25 ( V_2 , & V_19 ) ;
while ( 1 ) {
V_34 = F_8 ( V_8 ) ;
if ( ! V_8 || F_9 ( V_8 ) )
break;
V_34 = V_2 -> V_7 -> V_26 ( V_2 , V_8 ) ;
if ( V_34 < 0 )
break;
if ( F_10 ( V_34 ) )
V_2 -> V_3 = 0 ;
if ( F_10 ( ! V_2 -> V_3 ) ) {
V_8 = V_2 -> V_7 -> V_28 ( V_2 , V_8 , & V_19 ) ;
V_2 -> V_20 = V_19 ;
continue;
}
if ( V_2 -> V_3 < V_2 -> V_4 )
goto V_39;
V_2 -> V_7 -> V_29 ( V_2 , V_8 ) ;
F_11 ( V_2 -> V_23 ) ;
V_2 -> V_23 = F_4 ( V_2 -> V_4 <<= 1 , V_10 ) ;
if ( ! V_2 -> V_23 )
goto V_37;
V_2 -> V_3 = 0 ;
V_2 -> V_21 = 0 ;
V_19 = V_2 -> V_20 ;
V_8 = V_2 -> V_7 -> V_25 ( V_2 , & V_19 ) ;
}
V_2 -> V_7 -> V_29 ( V_2 , V_8 ) ;
V_2 -> V_3 = 0 ;
goto V_36;
V_39:
while ( V_2 -> V_3 < V_4 ) {
T_4 V_40 = V_2 -> V_3 ;
T_1 V_28 = V_19 ;
V_8 = V_2 -> V_7 -> V_28 ( V_2 , V_8 , & V_28 ) ;
if ( ! V_8 || F_9 ( V_8 ) ) {
V_34 = F_8 ( V_8 ) ;
break;
}
V_34 = V_2 -> V_7 -> V_26 ( V_2 , V_8 ) ;
if ( F_1 ( V_2 ) || V_34 ) {
V_2 -> V_3 = V_40 ;
if ( F_16 ( V_34 <= 0 ) )
break;
}
V_19 = V_28 ;
}
V_2 -> V_7 -> V_29 ( V_2 , V_8 ) ;
V_33 = F_14 ( V_2 -> V_3 , V_4 ) ;
V_34 = F_15 ( V_23 , V_2 -> V_23 , V_33 ) ;
if ( V_34 )
goto V_38;
V_32 += V_33 ;
V_2 -> V_3 -= V_33 ;
if ( V_2 -> V_3 )
V_2 -> V_22 = V_33 ;
else
V_19 ++ ;
V_2 -> V_20 = V_19 ;
V_36:
if ( ! V_32 )
V_32 = V_34 ;
else {
* V_31 += V_32 ;
V_2 -> V_35 += V_32 ;
}
V_5 -> V_15 = V_2 -> V_21 ;
F_17 ( & V_2 -> V_12 ) ;
return V_32 ;
V_37:
V_34 = - V_11 ;
goto V_36;
V_38:
V_34 = - V_41 ;
goto V_36;
}
T_1 F_18 ( struct V_5 * V_5 , T_1 V_18 , int V_42 )
{
struct V_1 * V_2 = V_5 -> V_9 ;
T_1 V_43 = - V_44 ;
F_13 ( & V_2 -> V_12 ) ;
V_2 -> V_21 = V_5 -> V_15 ;
switch ( V_42 ) {
case V_45 :
V_18 += V_5 -> V_46 ;
case V_47 :
if ( V_18 < 0 )
break;
V_43 = V_18 ;
if ( V_18 != V_2 -> V_35 ) {
while ( ( V_43 = F_7 ( V_2 , V_18 ) ) == - V_30 )
;
if ( V_43 ) {
V_5 -> V_46 = 0 ;
V_2 -> V_35 = 0 ;
V_2 -> V_21 = 0 ;
V_2 -> V_20 = 0 ;
V_2 -> V_3 = 0 ;
} else {
V_2 -> V_35 = V_18 ;
V_43 = V_5 -> V_46 = V_18 ;
}
}
}
V_5 -> V_15 = V_2 -> V_21 ;
F_17 ( & V_2 -> V_12 ) ;
return V_43 ;
}
int F_19 ( struct V_48 * V_48 , struct V_5 * V_5 )
{
struct V_1 * V_2 = V_5 -> V_9 ;
F_11 ( V_2 -> V_23 ) ;
F_11 ( V_2 ) ;
return 0 ;
}
int F_20 ( struct V_1 * V_2 , const char * V_49 , const char * V_50 )
{
char * V_51 = V_2 -> V_23 + V_2 -> V_4 ;
char * V_8 ;
char V_52 ;
for ( V_8 = V_2 -> V_23 + V_2 -> V_3 ; ( V_52 = * V_49 ) != '\0' && V_8 < V_51 ; V_49 ++ ) {
if ( ! strchr ( V_50 , V_52 ) ) {
* V_8 ++ = V_52 ;
continue;
}
if ( V_8 + 3 < V_51 ) {
* V_8 ++ = '\\' ;
* V_8 ++ = '0' + ( ( V_52 & 0300 ) >> 6 ) ;
* V_8 ++ = '0' + ( ( V_52 & 070 ) >> 3 ) ;
* V_8 ++ = '0' + ( V_52 & 07 ) ;
continue;
}
F_2 ( V_2 ) ;
return - 1 ;
}
V_2 -> V_3 = V_8 - V_2 -> V_23 ;
return 0 ;
}
int F_21 ( struct V_1 * V_2 , const char * V_53 , T_5 args )
{
int V_54 ;
if ( V_2 -> V_3 < V_2 -> V_4 ) {
V_54 = vsnprintf ( V_2 -> V_23 + V_2 -> V_3 , V_2 -> V_4 - V_2 -> V_3 , V_53 , args ) ;
if ( V_2 -> V_3 + V_54 < V_2 -> V_4 ) {
V_2 -> V_3 += V_54 ;
return 0 ;
}
}
F_2 ( V_2 ) ;
return - 1 ;
}
int F_22 ( struct V_1 * V_2 , const char * V_53 , ... )
{
int V_55 ;
T_5 args ;
va_start ( args , V_53 ) ;
V_55 = F_21 ( V_2 , V_53 , args ) ;
va_end ( args ) ;
return V_55 ;
}
char * F_23 ( char * V_49 , const char * V_8 , const char * V_50 )
{
while ( V_49 <= V_8 ) {
char V_52 = * V_8 ++ ;
if ( ! V_52 ) {
return V_49 ;
} else if ( ! strchr ( V_50 , V_52 ) ) {
* V_49 ++ = V_52 ;
} else if ( V_49 + 4 > V_8 ) {
break;
} else {
* V_49 ++ = '\\' ;
* V_49 ++ = '0' + ( ( V_52 & 0300 ) >> 6 ) ;
* V_49 ++ = '0' + ( ( V_52 & 070 ) >> 3 ) ;
* V_49 ++ = '0' + ( V_52 & 07 ) ;
}
}
return NULL ;
}
int F_24 ( struct V_1 * V_2 , const struct V_56 * V_56 , const char * V_50 )
{
char * V_23 ;
T_4 V_4 = F_25 ( V_2 , & V_23 ) ;
int V_57 = - 1 ;
if ( V_4 ) {
char * V_8 = F_26 ( V_56 , V_23 , V_4 ) ;
if ( ! F_9 ( V_8 ) ) {
char * V_51 = F_23 ( V_23 , V_8 , V_50 ) ;
if ( V_51 )
V_57 = V_51 - V_23 ;
}
}
F_27 ( V_2 , V_57 ) ;
return V_57 ;
}
int F_28 ( struct V_1 * V_2 , const struct V_56 * V_56 ,
const struct V_56 * V_58 , const char * V_50 )
{
char * V_23 ;
T_4 V_4 = F_25 ( V_2 , & V_23 ) ;
int V_57 = - V_59 ;
if ( V_4 ) {
char * V_8 ;
V_8 = F_29 ( V_56 , V_58 , V_23 , V_4 ) ;
if ( ! V_8 )
return V_60 ;
V_57 = F_8 ( V_8 ) ;
if ( ! F_9 ( V_8 ) ) {
char * V_51 = F_23 ( V_23 , V_8 , V_50 ) ;
if ( V_51 )
V_57 = V_51 - V_23 ;
else
V_57 = - V_59 ;
}
}
F_27 ( V_2 , V_57 ) ;
return V_57 < 0 && V_57 != - V_59 ? V_57 : 0 ;
}
int F_30 ( struct V_1 * V_2 , struct V_61 * V_61 , const char * V_50 )
{
char * V_23 ;
T_4 V_4 = F_25 ( V_2 , & V_23 ) ;
int V_57 = - 1 ;
if ( V_4 ) {
char * V_8 = F_31 ( V_61 , V_23 , V_4 ) ;
if ( ! F_9 ( V_8 ) ) {
char * V_51 = F_23 ( V_23 , V_8 , V_50 ) ;
if ( V_51 )
V_57 = V_51 - V_23 ;
}
}
F_27 ( V_2 , V_57 ) ;
return V_57 ;
}
int F_32 ( struct V_1 * V_2 , const unsigned long * V_62 ,
unsigned int V_63 )
{
if ( V_2 -> V_3 < V_2 -> V_4 ) {
int V_54 = F_33 ( V_2 -> V_23 + V_2 -> V_3 ,
V_2 -> V_4 - V_2 -> V_3 , V_62 , V_63 ) ;
if ( V_2 -> V_3 + V_54 < V_2 -> V_4 ) {
V_2 -> V_3 += V_54 ;
return 0 ;
}
}
F_2 ( V_2 ) ;
return - 1 ;
}
int F_34 ( struct V_1 * V_2 , const unsigned long * V_62 ,
unsigned int V_63 )
{
if ( V_2 -> V_3 < V_2 -> V_4 ) {
int V_54 = F_35 ( V_2 -> V_23 + V_2 -> V_3 ,
V_2 -> V_4 - V_2 -> V_3 , V_62 , V_63 ) ;
if ( V_2 -> V_3 + V_54 < V_2 -> V_4 ) {
V_2 -> V_3 += V_54 ;
return 0 ;
}
}
F_2 ( V_2 ) ;
return - 1 ;
}
static void * F_36 ( struct V_1 * V_8 , T_1 * V_19 )
{
return NULL + ( * V_19 == 0 ) ;
}
static void * F_37 ( struct V_1 * V_8 , void * V_64 , T_1 * V_19 )
{
++ * V_19 ;
return NULL ;
}
static void F_38 ( struct V_1 * V_8 , void * V_64 )
{
}
int F_39 ( struct V_5 * V_5 , int (* V_26)( struct V_1 * , void * ) ,
void * V_65 )
{
struct V_6 * V_7 = F_4 ( sizeof( * V_7 ) , V_10 ) ;
int V_57 = - V_11 ;
if ( V_7 ) {
V_7 -> V_25 = F_36 ;
V_7 -> V_28 = F_37 ;
V_7 -> V_29 = F_38 ;
V_7 -> V_26 = V_26 ;
V_57 = F_3 ( V_5 , V_7 ) ;
if ( ! V_57 )
( (struct V_1 * ) V_5 -> V_9 ) -> V_66 = V_65 ;
else
F_11 ( V_7 ) ;
}
return V_57 ;
}
int F_40 ( struct V_5 * V_5 , int (* V_26)( struct V_1 * , void * ) ,
void * V_65 , T_4 V_4 )
{
char * V_23 = F_4 ( V_4 , V_10 ) ;
int V_55 ;
if ( ! V_23 )
return - V_11 ;
V_55 = F_39 ( V_5 , V_26 , V_65 ) ;
if ( V_55 ) {
F_11 ( V_23 ) ;
return V_55 ;
}
( (struct V_1 * ) V_5 -> V_9 ) -> V_23 = V_23 ;
( (struct V_1 * ) V_5 -> V_9 ) -> V_4 = V_4 ;
return 0 ;
}
int F_41 ( struct V_48 * V_48 , struct V_5 * V_5 )
{
const struct V_6 * V_7 = ( (struct V_1 * ) V_5 -> V_9 ) -> V_7 ;
int V_57 = F_19 ( V_48 , V_5 ) ;
F_11 ( V_7 ) ;
return V_57 ;
}
int F_42 ( struct V_48 * V_48 , struct V_5 * V_5 )
{
struct V_1 * V_67 = V_5 -> V_9 ;
F_11 ( V_67 -> V_66 ) ;
V_67 -> V_66 = NULL ;
return F_19 ( V_48 , V_5 ) ;
}
void * F_43 ( struct V_5 * V_53 , const struct V_6 * V_68 ,
int V_69 )
{
int V_70 ;
void * V_66 ;
struct V_1 * V_67 ;
V_66 = F_44 ( V_69 , V_10 ) ;
if ( V_66 == NULL )
goto V_71;
V_70 = F_3 ( V_53 , V_68 ) ;
if ( V_70 < 0 )
goto V_72;
V_67 = V_53 -> V_9 ;
V_67 -> V_66 = V_66 ;
return V_66 ;
V_72:
F_11 ( V_66 ) ;
V_71:
return NULL ;
}
int F_45 ( struct V_5 * V_73 , const struct V_6 * V_68 ,
int V_69 )
{
return F_43 ( V_73 , V_68 , V_69 ) ? 0 : - V_11 ;
}
int F_46 ( struct V_1 * V_2 , char V_52 )
{
if ( V_2 -> V_3 < V_2 -> V_4 ) {
V_2 -> V_23 [ V_2 -> V_3 ++ ] = V_52 ;
return 0 ;
}
return - 1 ;
}
int F_47 ( struct V_1 * V_2 , const char * V_49 )
{
int V_54 = strlen ( V_49 ) ;
if ( V_2 -> V_3 + V_54 < V_2 -> V_4 ) {
memcpy ( V_2 -> V_23 + V_2 -> V_3 , V_49 , V_54 ) ;
V_2 -> V_3 += V_54 ;
return 0 ;
}
F_2 ( V_2 ) ;
return - 1 ;
}
int F_48 ( struct V_1 * V_2 , char V_74 ,
unsigned long long V_75 )
{
int V_54 ;
if ( V_2 -> V_3 + 2 >= V_2 -> V_4 )
goto V_76;
if ( V_74 )
V_2 -> V_23 [ V_2 -> V_3 ++ ] = V_74 ;
if ( V_75 < 10 ) {
V_2 -> V_23 [ V_2 -> V_3 ++ ] = V_75 + '0' ;
return 0 ;
}
V_54 = F_49 ( V_2 -> V_23 + V_2 -> V_3 , V_2 -> V_4 - V_2 -> V_3 , V_75 ) ;
if ( ! V_54 )
goto V_76;
V_2 -> V_3 += V_54 ;
return 0 ;
V_76:
F_2 ( V_2 ) ;
return - 1 ;
}
int F_50 ( struct V_1 * V_2 , char V_74 ,
long long V_75 )
{
if ( V_75 < 0 ) {
if ( V_2 -> V_3 + 3 >= V_2 -> V_4 ) {
F_2 ( V_2 ) ;
return - 1 ;
}
if ( V_74 )
V_2 -> V_23 [ V_2 -> V_3 ++ ] = V_74 ;
V_75 = - V_75 ;
V_74 = '-' ;
}
return F_48 ( V_2 , V_74 , V_75 ) ;
}
int F_51 ( struct V_1 * V_67 , const void * V_65 , T_4 V_54 )
{
if ( V_67 -> V_3 + V_54 < V_67 -> V_4 ) {
memcpy ( V_67 -> V_23 + V_67 -> V_3 , V_65 , V_54 ) ;
V_67 -> V_3 += V_54 ;
return 0 ;
}
F_2 ( V_67 ) ;
return - 1 ;
}
struct V_77 * F_52 ( struct V_77 * V_78 , T_1 V_19 )
{
struct V_77 * V_79 ;
F_53 (lh, head)
if ( V_19 -- == 0 )
return V_79 ;
return NULL ;
}
struct V_77 * F_54 ( struct V_77 * V_78 , T_1 V_19 )
{
if ( ! V_19 )
return V_78 ;
return F_52 ( V_78 , V_19 - 1 ) ;
}
struct V_77 * F_55 ( void * V_64 , struct V_77 * V_78 , T_1 * V_31 )
{
struct V_77 * V_79 ;
V_79 = ( (struct V_77 * ) V_64 ) -> V_28 ;
++ * V_31 ;
return V_79 == V_78 ? NULL : V_79 ;
}
struct V_80 * F_56 ( struct V_81 * V_78 , T_1 V_19 )
{
struct V_80 * V_82 ;
F_57 (node, head)
if ( V_19 -- == 0 )
return V_82 ;
return NULL ;
}
struct V_80 * F_58 ( struct V_81 * V_78 , T_1 V_19 )
{
if ( ! V_19 )
return V_83 ;
return F_56 ( V_78 , V_19 - 1 ) ;
}
struct V_80 * F_59 ( void * V_64 , struct V_81 * V_78 ,
T_1 * V_31 )
{
struct V_80 * V_82 = V_64 ;
++ * V_31 ;
if ( V_64 == V_83 )
return V_78 -> V_84 ;
else
return V_82 -> V_28 ;
}
struct V_80 * F_60 ( struct V_81 * V_78 ,
T_1 V_19 )
{
struct V_80 * V_82 ;
F_61 (node, head)
if ( V_19 -- == 0 )
return V_82 ;
return NULL ;
}
struct V_80 * F_62 ( struct V_81 * V_78 ,
T_1 V_19 )
{
if ( ! V_19 )
return V_83 ;
return F_60 ( V_78 , V_19 - 1 ) ;
}
struct V_80 * F_63 ( void * V_64 ,
struct V_81 * V_78 ,
T_1 * V_31 )
{
struct V_80 * V_82 = V_64 ;
++ * V_31 ;
if ( V_64 == V_83 )
return F_64 ( V_78 -> V_84 ) ;
else
return F_64 ( V_82 -> V_28 ) ;
}
struct V_80 *
F_65 ( struct V_81 T_6 * V_78 , int * V_85 , T_1 V_19 )
{
struct V_80 * V_82 ;
F_66 (*cpu) {
F_57 (node, per_cpu_ptr(head, *cpu)) {
if ( V_19 -- == 0 )
return V_82 ;
}
}
return NULL ;
}
struct V_80 *
F_67 ( void * V_64 , struct V_81 T_6 * V_78 ,
int * V_85 , T_1 * V_19 )
{
struct V_80 * V_82 = V_64 ;
++ * V_19 ;
if ( V_82 -> V_28 )
return V_82 -> V_28 ;
for ( * V_85 = F_68 ( * V_85 , V_86 ) ; * V_85 < V_87 ;
* V_85 = F_68 ( * V_85 , V_86 ) ) {
struct V_81 * V_88 = F_69 ( V_78 , * V_85 ) ;
if ( ! F_70 ( V_88 ) )
return V_88 -> V_84 ;
}
return NULL ;
}
