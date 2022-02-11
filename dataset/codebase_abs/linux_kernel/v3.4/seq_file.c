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
int F_20 ( struct V_1 * V_2 , const char * V_49 , ... )
{
T_5 args ;
int V_50 ;
if ( V_2 -> V_3 < V_2 -> V_4 ) {
va_start ( args , V_49 ) ;
V_50 = vsnprintf ( V_2 -> V_21 + V_2 -> V_3 , V_2 -> V_4 - V_2 -> V_3 , V_49 , args ) ;
va_end ( args ) ;
if ( V_2 -> V_3 + V_50 < V_2 -> V_4 ) {
V_2 -> V_3 += V_50 ;
return 0 ;
}
}
F_2 ( V_2 ) ;
return - 1 ;
}
char * F_21 ( char * V_45 , const char * V_8 , const char * V_46 )
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
int F_22 ( struct V_1 * V_2 , const struct V_51 * V_51 , const char * V_46 )
{
char * V_21 ;
T_4 V_4 = F_23 ( V_2 , & V_21 ) ;
int V_52 = - 1 ;
if ( V_4 ) {
char * V_8 = F_24 ( V_51 , V_21 , V_4 ) ;
if ( ! F_8 ( V_8 ) ) {
char * V_47 = F_21 ( V_21 , V_8 , V_46 ) ;
if ( V_47 )
V_52 = V_47 - V_21 ;
}
}
F_25 ( V_2 , V_52 ) ;
return V_52 ;
}
int F_26 ( struct V_1 * V_2 , const struct V_51 * V_51 ,
const struct V_51 * V_53 , const char * V_46 )
{
char * V_21 ;
T_4 V_4 = F_23 ( V_2 , & V_21 ) ;
int V_52 = - V_54 ;
if ( V_4 ) {
char * V_8 ;
V_8 = F_27 ( V_51 , V_53 , V_21 , V_4 ) ;
if ( ! V_8 )
return V_55 ;
V_52 = F_7 ( V_8 ) ;
if ( ! F_8 ( V_8 ) ) {
char * V_47 = F_21 ( V_21 , V_8 , V_46 ) ;
if ( V_47 )
V_52 = V_47 - V_21 ;
else
V_52 = - V_54 ;
}
}
F_25 ( V_2 , V_52 ) ;
return V_52 < 0 && V_52 != - V_54 ? V_52 : 0 ;
}
int F_28 ( struct V_1 * V_2 , struct V_56 * V_56 , const char * V_46 )
{
char * V_21 ;
T_4 V_4 = F_23 ( V_2 , & V_21 ) ;
int V_52 = - 1 ;
if ( V_4 ) {
char * V_8 = F_29 ( V_56 , V_21 , V_4 ) ;
if ( ! F_8 ( V_8 ) ) {
char * V_47 = F_21 ( V_21 , V_8 , V_46 ) ;
if ( V_47 )
V_52 = V_47 - V_21 ;
}
}
F_25 ( V_2 , V_52 ) ;
return V_52 ;
}
int F_30 ( struct V_1 * V_2 , const unsigned long * V_57 ,
unsigned int V_58 )
{
if ( V_2 -> V_3 < V_2 -> V_4 ) {
int V_50 = F_31 ( V_2 -> V_21 + V_2 -> V_3 ,
V_2 -> V_4 - V_2 -> V_3 , V_57 , V_58 ) ;
if ( V_2 -> V_3 + V_50 < V_2 -> V_4 ) {
V_2 -> V_3 += V_50 ;
return 0 ;
}
}
F_2 ( V_2 ) ;
return - 1 ;
}
int F_32 ( struct V_1 * V_2 , const unsigned long * V_57 ,
unsigned int V_58 )
{
if ( V_2 -> V_3 < V_2 -> V_4 ) {
int V_50 = F_33 ( V_2 -> V_21 + V_2 -> V_3 ,
V_2 -> V_4 - V_2 -> V_3 , V_57 , V_58 ) ;
if ( V_2 -> V_3 + V_50 < V_2 -> V_4 ) {
V_2 -> V_3 += V_50 ;
return 0 ;
}
}
F_2 ( V_2 ) ;
return - 1 ;
}
static void * F_34 ( struct V_1 * V_8 , T_1 * V_17 )
{
return NULL + ( * V_17 == 0 ) ;
}
static void * F_35 ( struct V_1 * V_8 , void * V_59 , T_1 * V_17 )
{
++ * V_17 ;
return NULL ;
}
static void F_36 ( struct V_1 * V_8 , void * V_59 )
{
}
int F_37 ( struct V_5 * V_5 , int (* V_24)( struct V_1 * , void * ) ,
void * V_60 )
{
struct V_6 * V_7 = F_4 ( sizeof( * V_7 ) , V_10 ) ;
int V_52 = - V_11 ;
if ( V_7 ) {
V_7 -> V_23 = F_34 ;
V_7 -> V_26 = F_35 ;
V_7 -> V_27 = F_36 ;
V_7 -> V_24 = V_24 ;
V_52 = F_3 ( V_5 , V_7 ) ;
if ( ! V_52 )
( (struct V_1 * ) V_5 -> V_9 ) -> V_61 = V_60 ;
else
F_10 ( V_7 ) ;
}
return V_52 ;
}
int F_38 ( struct V_44 * V_44 , struct V_5 * V_5 )
{
const struct V_6 * V_7 = ( (struct V_1 * ) V_5 -> V_9 ) -> V_7 ;
int V_52 = F_18 ( V_44 , V_5 ) ;
F_10 ( V_7 ) ;
return V_52 ;
}
int F_39 ( struct V_44 * V_44 , struct V_5 * V_5 )
{
struct V_1 * V_62 = V_5 -> V_9 ;
F_10 ( V_62 -> V_61 ) ;
V_62 -> V_61 = NULL ;
return F_18 ( V_44 , V_5 ) ;
}
void * F_40 ( struct V_5 * V_49 , const struct V_6 * V_63 ,
int V_64 )
{
int V_65 ;
void * V_61 ;
struct V_1 * V_62 ;
V_61 = F_41 ( V_64 , V_10 ) ;
if ( V_61 == NULL )
goto V_66;
V_65 = F_3 ( V_49 , V_63 ) ;
if ( V_65 < 0 )
goto V_67;
V_62 = V_49 -> V_9 ;
V_62 -> V_61 = V_61 ;
return V_61 ;
V_67:
F_10 ( V_61 ) ;
V_66:
return NULL ;
}
int F_42 ( struct V_5 * V_68 , const struct V_6 * V_63 ,
int V_64 )
{
return F_40 ( V_68 , V_63 , V_64 ) ? 0 : - V_11 ;
}
int F_43 ( struct V_1 * V_2 , char V_48 )
{
if ( V_2 -> V_3 < V_2 -> V_4 ) {
V_2 -> V_21 [ V_2 -> V_3 ++ ] = V_48 ;
return 0 ;
}
return - 1 ;
}
int F_44 ( struct V_1 * V_2 , const char * V_45 )
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
int F_45 ( struct V_1 * V_2 , char V_69 ,
unsigned long long V_70 )
{
int V_50 ;
if ( V_2 -> V_3 + 2 >= V_2 -> V_4 )
goto V_71;
if ( V_69 )
V_2 -> V_21 [ V_2 -> V_3 ++ ] = V_69 ;
if ( V_70 < 10 ) {
V_2 -> V_21 [ V_2 -> V_3 ++ ] = V_70 + '0' ;
return 0 ;
}
V_50 = F_46 ( V_2 -> V_21 + V_2 -> V_3 , V_2 -> V_4 - V_2 -> V_3 , V_70 ) ;
if ( ! V_50 )
goto V_71;
V_2 -> V_3 += V_50 ;
return 0 ;
V_71:
F_2 ( V_2 ) ;
return - 1 ;
}
int F_47 ( struct V_1 * V_2 , char V_69 ,
long long V_70 )
{
if ( V_70 < 0 ) {
if ( V_2 -> V_3 + 3 >= V_2 -> V_4 ) {
F_2 ( V_2 ) ;
return - 1 ;
}
if ( V_69 )
V_2 -> V_21 [ V_2 -> V_3 ++ ] = V_69 ;
V_70 = - V_70 ;
V_69 = '-' ;
}
return F_45 ( V_2 , V_69 , V_70 ) ;
}
int F_48 ( struct V_1 * V_62 , const void * V_60 , T_4 V_50 )
{
if ( V_62 -> V_3 + V_50 < V_62 -> V_4 ) {
memcpy ( V_62 -> V_21 + V_62 -> V_3 , V_60 , V_50 ) ;
V_62 -> V_3 += V_50 ;
return 0 ;
}
F_2 ( V_62 ) ;
return - 1 ;
}
struct V_72 * F_49 ( struct V_72 * V_73 , T_1 V_17 )
{
struct V_72 * V_74 ;
F_50 (lh, head)
if ( V_17 -- == 0 )
return V_74 ;
return NULL ;
}
struct V_72 * F_51 ( struct V_72 * V_73 , T_1 V_17 )
{
if ( ! V_17 )
return V_73 ;
return F_49 ( V_73 , V_17 - 1 ) ;
}
struct V_72 * F_52 ( void * V_59 , struct V_72 * V_73 , T_1 * V_29 )
{
struct V_72 * V_74 ;
V_74 = ( (struct V_72 * ) V_59 ) -> V_26 ;
++ * V_29 ;
return V_74 == V_73 ? NULL : V_74 ;
}
struct V_75 * F_53 ( struct V_76 * V_73 , T_1 V_17 )
{
struct V_75 * V_77 ;
F_54 (node, head)
if ( V_17 -- == 0 )
return V_77 ;
return NULL ;
}
struct V_75 * F_55 ( struct V_76 * V_73 , T_1 V_17 )
{
if ( ! V_17 )
return V_78 ;
return F_53 ( V_73 , V_17 - 1 ) ;
}
struct V_75 * F_56 ( void * V_59 , struct V_76 * V_73 ,
T_1 * V_29 )
{
struct V_75 * V_77 = V_59 ;
++ * V_29 ;
if ( V_59 == V_78 )
return V_73 -> V_79 ;
else
return V_77 -> V_26 ;
}
struct V_75 * F_57 ( struct V_76 * V_73 ,
T_1 V_17 )
{
struct V_75 * V_77 ;
F_58 (node, head)
if ( V_17 -- == 0 )
return V_77 ;
return NULL ;
}
struct V_75 * F_59 ( struct V_76 * V_73 ,
T_1 V_17 )
{
if ( ! V_17 )
return V_78 ;
return F_57 ( V_73 , V_17 - 1 ) ;
}
struct V_75 * F_60 ( void * V_59 ,
struct V_76 * V_73 ,
T_1 * V_29 )
{
struct V_75 * V_77 = V_59 ;
++ * V_29 ;
if ( V_59 == V_78 )
return F_61 ( V_73 -> V_79 ) ;
else
return F_61 ( V_77 -> V_26 ) ;
}
