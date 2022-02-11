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
V_5 -> V_13 = 0 ;
V_5 -> V_14 &= ~ V_15 ;
return 0 ;
}
static int F_6 ( struct V_1 * V_2 , T_1 V_16 )
{
T_1 V_17 = 0 , V_18 ;
int error = 0 ;
void * V_8 ;
V_2 -> V_19 = 0 ;
V_18 = 0 ;
V_2 -> V_3 = V_2 -> V_20 = 0 ;
if ( ! V_16 ) {
V_2 -> V_18 = V_18 ;
return 0 ;
}
if ( ! V_2 -> V_21 ) {
V_2 -> V_21 = F_4 ( V_2 -> V_4 = V_22 , V_10 ) ;
if ( ! V_2 -> V_21 )
return - V_11 ;
}
V_8 = V_2 -> V_7 -> V_23 ( V_2 , & V_18 ) ;
while ( V_8 ) {
error = F_7 ( V_8 ) ;
if ( F_8 ( V_8 ) )
break;
error = V_2 -> V_7 -> V_24 ( V_2 , V_8 ) ;
if ( error < 0 )
break;
if ( F_9 ( error ) ) {
error = 0 ;
V_2 -> V_3 = 0 ;
}
if ( F_1 ( V_2 ) )
goto V_25;
if ( V_17 + V_2 -> V_3 > V_16 ) {
V_2 -> V_20 = V_16 - V_17 ;
V_2 -> V_3 -= V_2 -> V_20 ;
V_2 -> V_18 = V_18 ;
break;
}
V_17 += V_2 -> V_3 ;
V_2 -> V_3 = 0 ;
if ( V_17 == V_16 ) {
V_18 ++ ;
V_2 -> V_18 = V_18 ;
break;
}
V_8 = V_2 -> V_7 -> V_26 ( V_2 , V_8 , & V_18 ) ;
}
V_2 -> V_7 -> V_27 ( V_2 , V_8 ) ;
V_2 -> V_18 = V_18 ;
return error ;
V_25:
V_2 -> V_7 -> V_27 ( V_2 , V_8 ) ;
F_10 ( V_2 -> V_21 ) ;
V_2 -> V_21 = F_4 ( V_2 -> V_4 <<= 1 , V_10 ) ;
return ! V_2 -> V_21 ? - V_11 : - V_28 ;
}
T_2 F_11 ( struct V_5 * V_5 , char T_3 * V_21 , T_4 V_4 , T_1 * V_29 )
{
struct V_1 * V_2 = V_5 -> V_9 ;
T_4 V_30 = 0 ;
T_1 V_17 ;
T_4 V_31 ;
void * V_8 ;
int V_32 = 0 ;
F_12 ( & V_2 -> V_12 ) ;
V_2 -> V_19 = V_5 -> V_13 ;
if ( F_9 ( * V_29 != V_2 -> V_33 ) ) {
while ( ( V_32 = F_6 ( V_2 , * V_29 ) ) == - V_28 )
;
if ( V_32 ) {
V_2 -> V_33 = 0 ;
V_2 -> V_19 = 0 ;
V_2 -> V_18 = 0 ;
V_2 -> V_3 = 0 ;
goto V_34;
} else {
V_2 -> V_33 = * V_29 ;
}
}
if ( ! V_2 -> V_21 ) {
V_2 -> V_21 = F_4 ( V_2 -> V_4 = V_22 , V_10 ) ;
if ( ! V_2 -> V_21 )
goto V_35;
}
if ( V_2 -> V_3 ) {
V_31 = F_13 ( V_2 -> V_3 , V_4 ) ;
V_32 = F_14 ( V_21 , V_2 -> V_21 + V_2 -> V_20 , V_31 ) ;
if ( V_32 )
goto V_36;
V_2 -> V_3 -= V_31 ;
V_2 -> V_20 += V_31 ;
V_4 -= V_31 ;
V_21 += V_31 ;
V_30 += V_31 ;
if ( ! V_2 -> V_3 )
V_2 -> V_18 ++ ;
if ( ! V_4 )
goto V_34;
}
V_17 = V_2 -> V_18 ;
V_8 = V_2 -> V_7 -> V_23 ( V_2 , & V_17 ) ;
while ( 1 ) {
V_32 = F_7 ( V_8 ) ;
if ( ! V_8 || F_8 ( V_8 ) )
break;
V_32 = V_2 -> V_7 -> V_24 ( V_2 , V_8 ) ;
if ( V_32 < 0 )
break;
if ( F_9 ( V_32 ) )
V_2 -> V_3 = 0 ;
if ( F_9 ( ! V_2 -> V_3 ) ) {
V_8 = V_2 -> V_7 -> V_26 ( V_2 , V_8 , & V_17 ) ;
V_2 -> V_18 = V_17 ;
continue;
}
if ( V_2 -> V_3 < V_2 -> V_4 )
goto V_37;
V_2 -> V_7 -> V_27 ( V_2 , V_8 ) ;
F_10 ( V_2 -> V_21 ) ;
V_2 -> V_21 = F_4 ( V_2 -> V_4 <<= 1 , V_10 ) ;
if ( ! V_2 -> V_21 )
goto V_35;
V_2 -> V_3 = 0 ;
V_2 -> V_19 = 0 ;
V_17 = V_2 -> V_18 ;
V_8 = V_2 -> V_7 -> V_23 ( V_2 , & V_17 ) ;
}
V_2 -> V_7 -> V_27 ( V_2 , V_8 ) ;
V_2 -> V_3 = 0 ;
goto V_34;
V_37:
while ( V_2 -> V_3 < V_4 ) {
T_4 V_38 = V_2 -> V_3 ;
T_1 V_26 = V_17 ;
V_8 = V_2 -> V_7 -> V_26 ( V_2 , V_8 , & V_26 ) ;
if ( ! V_8 || F_8 ( V_8 ) ) {
V_32 = F_7 ( V_8 ) ;
break;
}
V_32 = V_2 -> V_7 -> V_24 ( V_2 , V_8 ) ;
if ( F_1 ( V_2 ) || V_32 ) {
V_2 -> V_3 = V_38 ;
if ( F_15 ( V_32 <= 0 ) )
break;
}
V_17 = V_26 ;
}
V_2 -> V_7 -> V_27 ( V_2 , V_8 ) ;
V_31 = F_13 ( V_2 -> V_3 , V_4 ) ;
V_32 = F_14 ( V_21 , V_2 -> V_21 , V_31 ) ;
if ( V_32 )
goto V_36;
V_30 += V_31 ;
V_2 -> V_3 -= V_31 ;
if ( V_2 -> V_3 )
V_2 -> V_20 = V_31 ;
else
V_17 ++ ;
V_2 -> V_18 = V_17 ;
V_34:
if ( ! V_30 )
V_30 = V_32 ;
else {
* V_29 += V_30 ;
V_2 -> V_33 += V_30 ;
}
V_5 -> V_13 = V_2 -> V_19 ;
F_16 ( & V_2 -> V_12 ) ;
return V_30 ;
V_35:
V_32 = - V_11 ;
goto V_34;
V_36:
V_32 = - V_39 ;
goto V_34;
}
T_1 F_17 ( struct V_5 * V_5 , T_1 V_16 , int V_40 )
{
struct V_1 * V_2 = V_5 -> V_9 ;
T_1 V_41 = - V_42 ;
F_12 ( & V_2 -> V_12 ) ;
V_2 -> V_19 = V_5 -> V_13 ;
switch ( V_40 ) {
case 1 :
V_16 += V_5 -> V_43 ;
case 0 :
if ( V_16 < 0 )
break;
V_41 = V_16 ;
if ( V_16 != V_2 -> V_33 ) {
while ( ( V_41 = F_6 ( V_2 , V_16 ) ) == - V_28 )
;
if ( V_41 ) {
V_5 -> V_43 = 0 ;
V_2 -> V_33 = 0 ;
V_2 -> V_19 = 0 ;
V_2 -> V_18 = 0 ;
V_2 -> V_3 = 0 ;
} else {
V_2 -> V_33 = V_16 ;
V_41 = V_5 -> V_43 = V_16 ;
}
}
}
V_5 -> V_13 = V_2 -> V_19 ;
F_16 ( & V_2 -> V_12 ) ;
return V_41 ;
}
int F_18 ( struct V_44 * V_44 , struct V_5 * V_5 )
{
struct V_1 * V_2 = V_5 -> V_9 ;
F_10 ( V_2 -> V_21 ) ;
F_10 ( V_2 ) ;
return 0 ;
}
int F_19 ( struct V_1 * V_2 , const char * V_45 , const char * V_46 )
{
char * V_47 = V_2 -> V_21 + V_2 -> V_4 ;
char * V_8 ;
char V_48 ;
for ( V_8 = V_2 -> V_21 + V_2 -> V_3 ; ( V_48 = * V_45 ) != '\0' && V_8 < V_47 ; V_45 ++ ) {
if ( ! strchr ( V_46 , V_48 ) ) {
* V_8 ++ = V_48 ;
continue;
}
if ( V_8 + 3 < V_47 ) {
* V_8 ++ = '\\' ;
* V_8 ++ = '0' + ( ( V_48 & 0300 ) >> 6 ) ;
* V_8 ++ = '0' + ( ( V_48 & 070 ) >> 3 ) ;
* V_8 ++ = '0' + ( V_48 & 07 ) ;
continue;
}
F_2 ( V_2 ) ;
return - 1 ;
}
V_2 -> V_3 = V_8 - V_2 -> V_21 ;
return 0 ;
}
int F_20 ( struct V_1 * V_2 , const char * V_49 , T_5 args )
{
int V_50 ;
if ( V_2 -> V_3 < V_2 -> V_4 ) {
V_50 = vsnprintf ( V_2 -> V_21 + V_2 -> V_3 , V_2 -> V_4 - V_2 -> V_3 , V_49 , args ) ;
if ( V_2 -> V_3 + V_50 < V_2 -> V_4 ) {
V_2 -> V_3 += V_50 ;
return 0 ;
}
}
F_2 ( V_2 ) ;
return - 1 ;
}
int F_21 ( struct V_1 * V_2 , const char * V_49 , ... )
{
int V_51 ;
T_5 args ;
va_start ( args , V_49 ) ;
V_51 = F_20 ( V_2 , V_49 , args ) ;
va_end ( args ) ;
return V_51 ;
}
char * F_22 ( char * V_45 , const char * V_8 , const char * V_46 )
{
while ( V_45 <= V_8 ) {
char V_48 = * V_8 ++ ;
if ( ! V_48 ) {
return V_45 ;
} else if ( ! strchr ( V_46 , V_48 ) ) {
* V_45 ++ = V_48 ;
} else if ( V_45 + 4 > V_8 ) {
break;
} else {
* V_45 ++ = '\\' ;
* V_45 ++ = '0' + ( ( V_48 & 0300 ) >> 6 ) ;
* V_45 ++ = '0' + ( ( V_48 & 070 ) >> 3 ) ;
* V_45 ++ = '0' + ( V_48 & 07 ) ;
}
}
return NULL ;
}
int F_23 ( struct V_1 * V_2 , const struct V_52 * V_52 , const char * V_46 )
{
char * V_21 ;
T_4 V_4 = F_24 ( V_2 , & V_21 ) ;
int V_53 = - 1 ;
if ( V_4 ) {
char * V_8 = F_25 ( V_52 , V_21 , V_4 ) ;
if ( ! F_8 ( V_8 ) ) {
char * V_47 = F_22 ( V_21 , V_8 , V_46 ) ;
if ( V_47 )
V_53 = V_47 - V_21 ;
}
}
F_26 ( V_2 , V_53 ) ;
return V_53 ;
}
int F_27 ( struct V_1 * V_2 , const struct V_52 * V_52 ,
const struct V_52 * V_54 , const char * V_46 )
{
char * V_21 ;
T_4 V_4 = F_24 ( V_2 , & V_21 ) ;
int V_53 = - V_55 ;
if ( V_4 ) {
char * V_8 ;
V_8 = F_28 ( V_52 , V_54 , V_21 , V_4 ) ;
if ( ! V_8 )
return V_56 ;
V_53 = F_7 ( V_8 ) ;
if ( ! F_8 ( V_8 ) ) {
char * V_47 = F_22 ( V_21 , V_8 , V_46 ) ;
if ( V_47 )
V_53 = V_47 - V_21 ;
else
V_53 = - V_55 ;
}
}
F_26 ( V_2 , V_53 ) ;
return V_53 < 0 && V_53 != - V_55 ? V_53 : 0 ;
}
int F_29 ( struct V_1 * V_2 , struct V_57 * V_57 , const char * V_46 )
{
char * V_21 ;
T_4 V_4 = F_24 ( V_2 , & V_21 ) ;
int V_53 = - 1 ;
if ( V_4 ) {
char * V_8 = F_30 ( V_57 , V_21 , V_4 ) ;
if ( ! F_8 ( V_8 ) ) {
char * V_47 = F_22 ( V_21 , V_8 , V_46 ) ;
if ( V_47 )
V_53 = V_47 - V_21 ;
}
}
F_26 ( V_2 , V_53 ) ;
return V_53 ;
}
int F_31 ( struct V_1 * V_2 , const unsigned long * V_58 ,
unsigned int V_59 )
{
if ( V_2 -> V_3 < V_2 -> V_4 ) {
int V_50 = F_32 ( V_2 -> V_21 + V_2 -> V_3 ,
V_2 -> V_4 - V_2 -> V_3 , V_58 , V_59 ) ;
if ( V_2 -> V_3 + V_50 < V_2 -> V_4 ) {
V_2 -> V_3 += V_50 ;
return 0 ;
}
}
F_2 ( V_2 ) ;
return - 1 ;
}
int F_33 ( struct V_1 * V_2 , const unsigned long * V_58 ,
unsigned int V_59 )
{
if ( V_2 -> V_3 < V_2 -> V_4 ) {
int V_50 = F_34 ( V_2 -> V_21 + V_2 -> V_3 ,
V_2 -> V_4 - V_2 -> V_3 , V_58 , V_59 ) ;
if ( V_2 -> V_3 + V_50 < V_2 -> V_4 ) {
V_2 -> V_3 += V_50 ;
return 0 ;
}
}
F_2 ( V_2 ) ;
return - 1 ;
}
static void * F_35 ( struct V_1 * V_8 , T_1 * V_17 )
{
return NULL + ( * V_17 == 0 ) ;
}
static void * F_36 ( struct V_1 * V_8 , void * V_60 , T_1 * V_17 )
{
++ * V_17 ;
return NULL ;
}
static void F_37 ( struct V_1 * V_8 , void * V_60 )
{
}
int F_38 ( struct V_5 * V_5 , int (* V_24)( struct V_1 * , void * ) ,
void * V_61 )
{
struct V_6 * V_7 = F_4 ( sizeof( * V_7 ) , V_10 ) ;
int V_53 = - V_11 ;
if ( V_7 ) {
V_7 -> V_23 = F_35 ;
V_7 -> V_26 = F_36 ;
V_7 -> V_27 = F_37 ;
V_7 -> V_24 = V_24 ;
V_53 = F_3 ( V_5 , V_7 ) ;
if ( ! V_53 )
( (struct V_1 * ) V_5 -> V_9 ) -> V_62 = V_61 ;
else
F_10 ( V_7 ) ;
}
return V_53 ;
}
int F_39 ( struct V_44 * V_44 , struct V_5 * V_5 )
{
const struct V_6 * V_7 = ( (struct V_1 * ) V_5 -> V_9 ) -> V_7 ;
int V_53 = F_18 ( V_44 , V_5 ) ;
F_10 ( V_7 ) ;
return V_53 ;
}
int F_40 ( struct V_44 * V_44 , struct V_5 * V_5 )
{
struct V_1 * V_63 = V_5 -> V_9 ;
F_10 ( V_63 -> V_62 ) ;
V_63 -> V_62 = NULL ;
return F_18 ( V_44 , V_5 ) ;
}
void * F_41 ( struct V_5 * V_49 , const struct V_6 * V_64 ,
int V_65 )
{
int V_66 ;
void * V_62 ;
struct V_1 * V_63 ;
V_62 = F_42 ( V_65 , V_10 ) ;
if ( V_62 == NULL )
goto V_67;
V_66 = F_3 ( V_49 , V_64 ) ;
if ( V_66 < 0 )
goto V_68;
V_63 = V_49 -> V_9 ;
V_63 -> V_62 = V_62 ;
return V_62 ;
V_68:
F_10 ( V_62 ) ;
V_67:
return NULL ;
}
int F_43 ( struct V_5 * V_69 , const struct V_6 * V_64 ,
int V_65 )
{
return F_41 ( V_69 , V_64 , V_65 ) ? 0 : - V_11 ;
}
int F_44 ( struct V_1 * V_2 , char V_48 )
{
if ( V_2 -> V_3 < V_2 -> V_4 ) {
V_2 -> V_21 [ V_2 -> V_3 ++ ] = V_48 ;
return 0 ;
}
return - 1 ;
}
int F_45 ( struct V_1 * V_2 , const char * V_45 )
{
int V_50 = strlen ( V_45 ) ;
if ( V_2 -> V_3 + V_50 < V_2 -> V_4 ) {
memcpy ( V_2 -> V_21 + V_2 -> V_3 , V_45 , V_50 ) ;
V_2 -> V_3 += V_50 ;
return 0 ;
}
F_2 ( V_2 ) ;
return - 1 ;
}
int F_46 ( struct V_1 * V_2 , char V_70 ,
unsigned long long V_71 )
{
int V_50 ;
if ( V_2 -> V_3 + 2 >= V_2 -> V_4 )
goto V_72;
if ( V_70 )
V_2 -> V_21 [ V_2 -> V_3 ++ ] = V_70 ;
if ( V_71 < 10 ) {
V_2 -> V_21 [ V_2 -> V_3 ++ ] = V_71 + '0' ;
return 0 ;
}
V_50 = F_47 ( V_2 -> V_21 + V_2 -> V_3 , V_2 -> V_4 - V_2 -> V_3 , V_71 ) ;
if ( ! V_50 )
goto V_72;
V_2 -> V_3 += V_50 ;
return 0 ;
V_72:
F_2 ( V_2 ) ;
return - 1 ;
}
int F_48 ( struct V_1 * V_2 , char V_70 ,
long long V_71 )
{
if ( V_71 < 0 ) {
if ( V_2 -> V_3 + 3 >= V_2 -> V_4 ) {
F_2 ( V_2 ) ;
return - 1 ;
}
if ( V_70 )
V_2 -> V_21 [ V_2 -> V_3 ++ ] = V_70 ;
V_71 = - V_71 ;
V_70 = '-' ;
}
return F_46 ( V_2 , V_70 , V_71 ) ;
}
int F_49 ( struct V_1 * V_63 , const void * V_61 , T_4 V_50 )
{
if ( V_63 -> V_3 + V_50 < V_63 -> V_4 ) {
memcpy ( V_63 -> V_21 + V_63 -> V_3 , V_61 , V_50 ) ;
V_63 -> V_3 += V_50 ;
return 0 ;
}
F_2 ( V_63 ) ;
return - 1 ;
}
struct V_73 * F_50 ( struct V_73 * V_74 , T_1 V_17 )
{
struct V_73 * V_75 ;
F_51 (lh, head)
if ( V_17 -- == 0 )
return V_75 ;
return NULL ;
}
struct V_73 * F_52 ( struct V_73 * V_74 , T_1 V_17 )
{
if ( ! V_17 )
return V_74 ;
return F_50 ( V_74 , V_17 - 1 ) ;
}
struct V_73 * F_53 ( void * V_60 , struct V_73 * V_74 , T_1 * V_29 )
{
struct V_73 * V_75 ;
V_75 = ( (struct V_73 * ) V_60 ) -> V_26 ;
++ * V_29 ;
return V_75 == V_74 ? NULL : V_75 ;
}
struct V_76 * F_54 ( struct V_77 * V_74 , T_1 V_17 )
{
struct V_76 * V_78 ;
F_55 (node, head)
if ( V_17 -- == 0 )
return V_78 ;
return NULL ;
}
struct V_76 * F_56 ( struct V_77 * V_74 , T_1 V_17 )
{
if ( ! V_17 )
return V_79 ;
return F_54 ( V_74 , V_17 - 1 ) ;
}
struct V_76 * F_57 ( void * V_60 , struct V_77 * V_74 ,
T_1 * V_29 )
{
struct V_76 * V_78 = V_60 ;
++ * V_29 ;
if ( V_60 == V_79 )
return V_74 -> V_80 ;
else
return V_78 -> V_26 ;
}
struct V_76 * F_58 ( struct V_77 * V_74 ,
T_1 V_17 )
{
struct V_76 * V_78 ;
F_59 (node, head)
if ( V_17 -- == 0 )
return V_78 ;
return NULL ;
}
struct V_76 * F_60 ( struct V_77 * V_74 ,
T_1 V_17 )
{
if ( ! V_17 )
return V_79 ;
return F_58 ( V_74 , V_17 - 1 ) ;
}
struct V_76 * F_61 ( void * V_60 ,
struct V_77 * V_74 ,
T_1 * V_29 )
{
struct V_76 * V_78 = V_60 ;
++ * V_29 ;
if ( V_60 == V_79 )
return F_62 ( V_74 -> V_80 ) ;
else
return F_62 ( V_78 -> V_26 ) ;
}
