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
case 1 :
V_18 += V_5 -> V_45 ;
case 0 :
if ( V_18 < 0 )
break;
V_43 = V_18 ;
if ( V_18 != V_2 -> V_35 ) {
while ( ( V_43 = F_7 ( V_2 , V_18 ) ) == - V_30 )
;
if ( V_43 ) {
V_5 -> V_45 = 0 ;
V_2 -> V_35 = 0 ;
V_2 -> V_21 = 0 ;
V_2 -> V_20 = 0 ;
V_2 -> V_3 = 0 ;
} else {
V_2 -> V_35 = V_18 ;
V_43 = V_5 -> V_45 = V_18 ;
}
}
}
V_5 -> V_15 = V_2 -> V_21 ;
F_17 ( & V_2 -> V_12 ) ;
return V_43 ;
}
int F_19 ( struct V_46 * V_46 , struct V_5 * V_5 )
{
struct V_1 * V_2 = V_5 -> V_9 ;
F_11 ( V_2 -> V_23 ) ;
F_11 ( V_2 ) ;
return 0 ;
}
int F_20 ( struct V_1 * V_2 , const char * V_47 , const char * V_48 )
{
char * V_49 = V_2 -> V_23 + V_2 -> V_4 ;
char * V_8 ;
char V_50 ;
for ( V_8 = V_2 -> V_23 + V_2 -> V_3 ; ( V_50 = * V_47 ) != '\0' && V_8 < V_49 ; V_47 ++ ) {
if ( ! strchr ( V_48 , V_50 ) ) {
* V_8 ++ = V_50 ;
continue;
}
if ( V_8 + 3 < V_49 ) {
* V_8 ++ = '\\' ;
* V_8 ++ = '0' + ( ( V_50 & 0300 ) >> 6 ) ;
* V_8 ++ = '0' + ( ( V_50 & 070 ) >> 3 ) ;
* V_8 ++ = '0' + ( V_50 & 07 ) ;
continue;
}
F_2 ( V_2 ) ;
return - 1 ;
}
V_2 -> V_3 = V_8 - V_2 -> V_23 ;
return 0 ;
}
int F_21 ( struct V_1 * V_2 , const char * V_51 , T_5 args )
{
int V_52 ;
if ( V_2 -> V_3 < V_2 -> V_4 ) {
V_52 = vsnprintf ( V_2 -> V_23 + V_2 -> V_3 , V_2 -> V_4 - V_2 -> V_3 , V_51 , args ) ;
if ( V_2 -> V_3 + V_52 < V_2 -> V_4 ) {
V_2 -> V_3 += V_52 ;
return 0 ;
}
}
F_2 ( V_2 ) ;
return - 1 ;
}
int F_22 ( struct V_1 * V_2 , const char * V_51 , ... )
{
int V_53 ;
T_5 args ;
va_start ( args , V_51 ) ;
V_53 = F_21 ( V_2 , V_51 , args ) ;
va_end ( args ) ;
return V_53 ;
}
char * F_23 ( char * V_47 , const char * V_8 , const char * V_48 )
{
while ( V_47 <= V_8 ) {
char V_50 = * V_8 ++ ;
if ( ! V_50 ) {
return V_47 ;
} else if ( ! strchr ( V_48 , V_50 ) ) {
* V_47 ++ = V_50 ;
} else if ( V_47 + 4 > V_8 ) {
break;
} else {
* V_47 ++ = '\\' ;
* V_47 ++ = '0' + ( ( V_50 & 0300 ) >> 6 ) ;
* V_47 ++ = '0' + ( ( V_50 & 070 ) >> 3 ) ;
* V_47 ++ = '0' + ( V_50 & 07 ) ;
}
}
return NULL ;
}
int F_24 ( struct V_1 * V_2 , const struct V_54 * V_54 , const char * V_48 )
{
char * V_23 ;
T_4 V_4 = F_25 ( V_2 , & V_23 ) ;
int V_55 = - 1 ;
if ( V_4 ) {
char * V_8 = F_26 ( V_54 , V_23 , V_4 ) ;
if ( ! F_9 ( V_8 ) ) {
char * V_49 = F_23 ( V_23 , V_8 , V_48 ) ;
if ( V_49 )
V_55 = V_49 - V_23 ;
}
}
F_27 ( V_2 , V_55 ) ;
return V_55 ;
}
int F_28 ( struct V_1 * V_2 , const struct V_54 * V_54 ,
const struct V_54 * V_56 , const char * V_48 )
{
char * V_23 ;
T_4 V_4 = F_25 ( V_2 , & V_23 ) ;
int V_55 = - V_57 ;
if ( V_4 ) {
char * V_8 ;
V_8 = F_29 ( V_54 , V_56 , V_23 , V_4 ) ;
if ( ! V_8 )
return V_58 ;
V_55 = F_8 ( V_8 ) ;
if ( ! F_9 ( V_8 ) ) {
char * V_49 = F_23 ( V_23 , V_8 , V_48 ) ;
if ( V_49 )
V_55 = V_49 - V_23 ;
else
V_55 = - V_57 ;
}
}
F_27 ( V_2 , V_55 ) ;
return V_55 < 0 && V_55 != - V_57 ? V_55 : 0 ;
}
int F_30 ( struct V_1 * V_2 , struct V_59 * V_59 , const char * V_48 )
{
char * V_23 ;
T_4 V_4 = F_25 ( V_2 , & V_23 ) ;
int V_55 = - 1 ;
if ( V_4 ) {
char * V_8 = F_31 ( V_59 , V_23 , V_4 ) ;
if ( ! F_9 ( V_8 ) ) {
char * V_49 = F_23 ( V_23 , V_8 , V_48 ) ;
if ( V_49 )
V_55 = V_49 - V_23 ;
}
}
F_27 ( V_2 , V_55 ) ;
return V_55 ;
}
int F_32 ( struct V_1 * V_2 , const unsigned long * V_60 ,
unsigned int V_61 )
{
if ( V_2 -> V_3 < V_2 -> V_4 ) {
int V_52 = F_33 ( V_2 -> V_23 + V_2 -> V_3 ,
V_2 -> V_4 - V_2 -> V_3 , V_60 , V_61 ) ;
if ( V_2 -> V_3 + V_52 < V_2 -> V_4 ) {
V_2 -> V_3 += V_52 ;
return 0 ;
}
}
F_2 ( V_2 ) ;
return - 1 ;
}
int F_34 ( struct V_1 * V_2 , const unsigned long * V_60 ,
unsigned int V_61 )
{
if ( V_2 -> V_3 < V_2 -> V_4 ) {
int V_52 = F_35 ( V_2 -> V_23 + V_2 -> V_3 ,
V_2 -> V_4 - V_2 -> V_3 , V_60 , V_61 ) ;
if ( V_2 -> V_3 + V_52 < V_2 -> V_4 ) {
V_2 -> V_3 += V_52 ;
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
static void * F_37 ( struct V_1 * V_8 , void * V_62 , T_1 * V_19 )
{
++ * V_19 ;
return NULL ;
}
static void F_38 ( struct V_1 * V_8 , void * V_62 )
{
}
int F_39 ( struct V_5 * V_5 , int (* V_26)( struct V_1 * , void * ) ,
void * V_63 )
{
struct V_6 * V_7 = F_4 ( sizeof( * V_7 ) , V_10 ) ;
int V_55 = - V_11 ;
if ( V_7 ) {
V_7 -> V_25 = F_36 ;
V_7 -> V_28 = F_37 ;
V_7 -> V_29 = F_38 ;
V_7 -> V_26 = V_26 ;
V_55 = F_3 ( V_5 , V_7 ) ;
if ( ! V_55 )
( (struct V_1 * ) V_5 -> V_9 ) -> V_64 = V_63 ;
else
F_11 ( V_7 ) ;
}
return V_55 ;
}
int F_40 ( struct V_46 * V_46 , struct V_5 * V_5 )
{
const struct V_6 * V_7 = ( (struct V_1 * ) V_5 -> V_9 ) -> V_7 ;
int V_55 = F_19 ( V_46 , V_5 ) ;
F_11 ( V_7 ) ;
return V_55 ;
}
int F_41 ( struct V_46 * V_46 , struct V_5 * V_5 )
{
struct V_1 * V_65 = V_5 -> V_9 ;
F_11 ( V_65 -> V_64 ) ;
V_65 -> V_64 = NULL ;
return F_19 ( V_46 , V_5 ) ;
}
void * F_42 ( struct V_5 * V_51 , const struct V_6 * V_66 ,
int V_67 )
{
int V_68 ;
void * V_64 ;
struct V_1 * V_65 ;
V_64 = F_43 ( V_67 , V_10 ) ;
if ( V_64 == NULL )
goto V_69;
V_68 = F_3 ( V_51 , V_66 ) ;
if ( V_68 < 0 )
goto V_70;
V_65 = V_51 -> V_9 ;
V_65 -> V_64 = V_64 ;
return V_64 ;
V_70:
F_11 ( V_64 ) ;
V_69:
return NULL ;
}
int F_44 ( struct V_5 * V_71 , const struct V_6 * V_66 ,
int V_67 )
{
return F_42 ( V_71 , V_66 , V_67 ) ? 0 : - V_11 ;
}
int F_45 ( struct V_1 * V_2 , char V_50 )
{
if ( V_2 -> V_3 < V_2 -> V_4 ) {
V_2 -> V_23 [ V_2 -> V_3 ++ ] = V_50 ;
return 0 ;
}
return - 1 ;
}
int F_46 ( struct V_1 * V_2 , const char * V_47 )
{
int V_52 = strlen ( V_47 ) ;
if ( V_2 -> V_3 + V_52 < V_2 -> V_4 ) {
memcpy ( V_2 -> V_23 + V_2 -> V_3 , V_47 , V_52 ) ;
V_2 -> V_3 += V_52 ;
return 0 ;
}
F_2 ( V_2 ) ;
return - 1 ;
}
int F_47 ( struct V_1 * V_2 , char V_72 ,
unsigned long long V_73 )
{
int V_52 ;
if ( V_2 -> V_3 + 2 >= V_2 -> V_4 )
goto V_74;
if ( V_72 )
V_2 -> V_23 [ V_2 -> V_3 ++ ] = V_72 ;
if ( V_73 < 10 ) {
V_2 -> V_23 [ V_2 -> V_3 ++ ] = V_73 + '0' ;
return 0 ;
}
V_52 = F_48 ( V_2 -> V_23 + V_2 -> V_3 , V_2 -> V_4 - V_2 -> V_3 , V_73 ) ;
if ( ! V_52 )
goto V_74;
V_2 -> V_3 += V_52 ;
return 0 ;
V_74:
F_2 ( V_2 ) ;
return - 1 ;
}
int F_49 ( struct V_1 * V_2 , char V_72 ,
long long V_73 )
{
if ( V_73 < 0 ) {
if ( V_2 -> V_3 + 3 >= V_2 -> V_4 ) {
F_2 ( V_2 ) ;
return - 1 ;
}
if ( V_72 )
V_2 -> V_23 [ V_2 -> V_3 ++ ] = V_72 ;
V_73 = - V_73 ;
V_72 = '-' ;
}
return F_47 ( V_2 , V_72 , V_73 ) ;
}
int F_50 ( struct V_1 * V_65 , const void * V_63 , T_4 V_52 )
{
if ( V_65 -> V_3 + V_52 < V_65 -> V_4 ) {
memcpy ( V_65 -> V_23 + V_65 -> V_3 , V_63 , V_52 ) ;
V_65 -> V_3 += V_52 ;
return 0 ;
}
F_2 ( V_65 ) ;
return - 1 ;
}
struct V_75 * F_51 ( struct V_75 * V_76 , T_1 V_19 )
{
struct V_75 * V_77 ;
F_52 (lh, head)
if ( V_19 -- == 0 )
return V_77 ;
return NULL ;
}
struct V_75 * F_53 ( struct V_75 * V_76 , T_1 V_19 )
{
if ( ! V_19 )
return V_76 ;
return F_51 ( V_76 , V_19 - 1 ) ;
}
struct V_75 * F_54 ( void * V_62 , struct V_75 * V_76 , T_1 * V_31 )
{
struct V_75 * V_77 ;
V_77 = ( (struct V_75 * ) V_62 ) -> V_28 ;
++ * V_31 ;
return V_77 == V_76 ? NULL : V_77 ;
}
struct V_78 * F_55 ( struct V_79 * V_76 , T_1 V_19 )
{
struct V_78 * V_80 ;
F_56 (node, head)
if ( V_19 -- == 0 )
return V_80 ;
return NULL ;
}
struct V_78 * F_57 ( struct V_79 * V_76 , T_1 V_19 )
{
if ( ! V_19 )
return V_81 ;
return F_55 ( V_76 , V_19 - 1 ) ;
}
struct V_78 * F_58 ( void * V_62 , struct V_79 * V_76 ,
T_1 * V_31 )
{
struct V_78 * V_80 = V_62 ;
++ * V_31 ;
if ( V_62 == V_81 )
return V_76 -> V_82 ;
else
return V_80 -> V_28 ;
}
struct V_78 * F_59 ( struct V_79 * V_76 ,
T_1 V_19 )
{
struct V_78 * V_80 ;
F_60 (node, head)
if ( V_19 -- == 0 )
return V_80 ;
return NULL ;
}
struct V_78 * F_61 ( struct V_79 * V_76 ,
T_1 V_19 )
{
if ( ! V_19 )
return V_81 ;
return F_59 ( V_76 , V_19 - 1 ) ;
}
struct V_78 * F_62 ( void * V_62 ,
struct V_79 * V_76 ,
T_1 * V_31 )
{
struct V_78 * V_80 = V_62 ;
++ * V_31 ;
if ( V_62 == V_81 )
return F_63 ( V_76 -> V_82 ) ;
else
return F_63 ( V_80 -> V_28 ) ;
}
