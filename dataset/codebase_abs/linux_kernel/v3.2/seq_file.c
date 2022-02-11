int F_1 ( struct V_1 * V_1 , const struct V_2 * V_3 )
{
struct V_4 * V_5 = V_1 -> V_6 ;
if ( ! V_5 ) {
V_5 = F_2 ( sizeof( * V_5 ) , V_7 ) ;
if ( ! V_5 )
return - V_8 ;
V_1 -> V_6 = V_5 ;
}
memset ( V_5 , 0 , sizeof( * V_5 ) ) ;
F_3 ( & V_5 -> V_9 ) ;
V_5 -> V_3 = V_3 ;
V_1 -> V_10 = 0 ;
V_1 -> V_11 &= ~ V_12 ;
return 0 ;
}
static int F_4 ( struct V_4 * V_13 , T_1 V_14 )
{
T_1 V_15 = 0 , V_16 ;
int error = 0 ;
void * V_5 ;
V_13 -> V_17 = 0 ;
V_16 = 0 ;
V_13 -> V_18 = V_13 -> V_19 = 0 ;
if ( ! V_14 ) {
V_13 -> V_16 = V_16 ;
return 0 ;
}
if ( ! V_13 -> V_20 ) {
V_13 -> V_20 = F_2 ( V_13 -> V_21 = V_22 , V_7 ) ;
if ( ! V_13 -> V_20 )
return - V_8 ;
}
V_5 = V_13 -> V_3 -> V_23 ( V_13 , & V_16 ) ;
while ( V_5 ) {
error = F_5 ( V_5 ) ;
if ( F_6 ( V_5 ) )
break;
error = V_13 -> V_3 -> V_24 ( V_13 , V_5 ) ;
if ( error < 0 )
break;
if ( F_7 ( error ) ) {
error = 0 ;
V_13 -> V_18 = 0 ;
}
if ( V_13 -> V_18 == V_13 -> V_21 )
goto V_25;
if ( V_15 + V_13 -> V_18 > V_14 ) {
V_13 -> V_19 = V_14 - V_15 ;
V_13 -> V_18 -= V_13 -> V_19 ;
V_13 -> V_16 = V_16 ;
break;
}
V_15 += V_13 -> V_18 ;
V_13 -> V_18 = 0 ;
if ( V_15 == V_14 ) {
V_16 ++ ;
V_13 -> V_16 = V_16 ;
break;
}
V_5 = V_13 -> V_3 -> V_26 ( V_13 , V_5 , & V_16 ) ;
}
V_13 -> V_3 -> V_27 ( V_13 , V_5 ) ;
V_13 -> V_16 = V_16 ;
return error ;
V_25:
V_13 -> V_3 -> V_27 ( V_13 , V_5 ) ;
F_8 ( V_13 -> V_20 ) ;
V_13 -> V_20 = F_2 ( V_13 -> V_21 <<= 1 , V_7 ) ;
return ! V_13 -> V_20 ? - V_8 : - V_28 ;
}
T_2 F_9 ( struct V_1 * V_1 , char T_3 * V_20 , T_4 V_21 , T_1 * V_29 )
{
struct V_4 * V_13 = V_1 -> V_6 ;
T_4 V_30 = 0 ;
T_1 V_15 ;
T_4 V_31 ;
void * V_5 ;
int V_32 = 0 ;
F_10 ( & V_13 -> V_9 ) ;
if ( F_7 ( * V_29 != V_13 -> V_33 ) ) {
V_13 -> V_33 = * V_29 ;
while ( ( V_32 = F_4 ( V_13 , * V_29 ) ) == - V_28 )
;
if ( V_32 ) {
V_13 -> V_33 = 0 ;
V_13 -> V_17 = 0 ;
V_13 -> V_16 = 0 ;
V_13 -> V_18 = 0 ;
goto V_34;
}
}
V_13 -> V_17 = V_1 -> V_10 ;
if ( ! V_13 -> V_20 ) {
V_13 -> V_20 = F_2 ( V_13 -> V_21 = V_22 , V_7 ) ;
if ( ! V_13 -> V_20 )
goto V_35;
}
if ( V_13 -> V_18 ) {
V_31 = F_11 ( V_13 -> V_18 , V_21 ) ;
V_32 = F_12 ( V_20 , V_13 -> V_20 + V_13 -> V_19 , V_31 ) ;
if ( V_32 )
goto V_36;
V_13 -> V_18 -= V_31 ;
V_13 -> V_19 += V_31 ;
V_21 -= V_31 ;
V_20 += V_31 ;
V_30 += V_31 ;
if ( ! V_13 -> V_18 )
V_13 -> V_16 ++ ;
if ( ! V_21 )
goto V_34;
}
V_15 = V_13 -> V_16 ;
V_5 = V_13 -> V_3 -> V_23 ( V_13 , & V_15 ) ;
while ( 1 ) {
V_32 = F_5 ( V_5 ) ;
if ( ! V_5 || F_6 ( V_5 ) )
break;
V_32 = V_13 -> V_3 -> V_24 ( V_13 , V_5 ) ;
if ( V_32 < 0 )
break;
if ( F_7 ( V_32 ) )
V_13 -> V_18 = 0 ;
if ( F_7 ( ! V_13 -> V_18 ) ) {
V_5 = V_13 -> V_3 -> V_26 ( V_13 , V_5 , & V_15 ) ;
V_13 -> V_16 = V_15 ;
continue;
}
if ( V_13 -> V_18 < V_13 -> V_21 )
goto V_37;
V_13 -> V_3 -> V_27 ( V_13 , V_5 ) ;
F_8 ( V_13 -> V_20 ) ;
V_13 -> V_20 = F_2 ( V_13 -> V_21 <<= 1 , V_7 ) ;
if ( ! V_13 -> V_20 )
goto V_35;
V_13 -> V_18 = 0 ;
V_13 -> V_17 = 0 ;
V_15 = V_13 -> V_16 ;
V_5 = V_13 -> V_3 -> V_23 ( V_13 , & V_15 ) ;
}
V_13 -> V_3 -> V_27 ( V_13 , V_5 ) ;
V_13 -> V_18 = 0 ;
goto V_34;
V_37:
while ( V_13 -> V_18 < V_21 ) {
T_4 V_38 = V_13 -> V_18 ;
T_1 V_26 = V_15 ;
V_5 = V_13 -> V_3 -> V_26 ( V_13 , V_5 , & V_26 ) ;
if ( ! V_5 || F_6 ( V_5 ) ) {
V_32 = F_5 ( V_5 ) ;
break;
}
V_32 = V_13 -> V_3 -> V_24 ( V_13 , V_5 ) ;
if ( V_13 -> V_18 == V_13 -> V_21 || V_32 ) {
V_13 -> V_18 = V_38 ;
if ( F_13 ( V_32 <= 0 ) )
break;
}
V_15 = V_26 ;
}
V_13 -> V_3 -> V_27 ( V_13 , V_5 ) ;
V_31 = F_11 ( V_13 -> V_18 , V_21 ) ;
V_32 = F_12 ( V_20 , V_13 -> V_20 , V_31 ) ;
if ( V_32 )
goto V_36;
V_30 += V_31 ;
V_13 -> V_18 -= V_31 ;
if ( V_13 -> V_18 )
V_13 -> V_19 = V_31 ;
else
V_15 ++ ;
V_13 -> V_16 = V_15 ;
V_34:
if ( ! V_30 )
V_30 = V_32 ;
else {
* V_29 += V_30 ;
V_13 -> V_33 += V_30 ;
}
V_1 -> V_10 = V_13 -> V_17 ;
F_14 ( & V_13 -> V_9 ) ;
return V_30 ;
V_35:
V_32 = - V_8 ;
goto V_34;
V_36:
V_32 = - V_39 ;
goto V_34;
}
T_1 F_15 ( struct V_1 * V_1 , T_1 V_14 , int V_40 )
{
struct V_4 * V_13 = V_1 -> V_6 ;
T_1 V_41 = - V_42 ;
F_10 ( & V_13 -> V_9 ) ;
V_13 -> V_17 = V_1 -> V_10 ;
switch ( V_40 ) {
case 1 :
V_14 += V_1 -> V_43 ;
case 0 :
if ( V_14 < 0 )
break;
V_41 = V_14 ;
if ( V_14 != V_13 -> V_33 ) {
while ( ( V_41 = F_4 ( V_13 , V_14 ) ) == - V_28 )
;
if ( V_41 ) {
V_1 -> V_43 = 0 ;
V_13 -> V_33 = 0 ;
V_13 -> V_17 = 0 ;
V_13 -> V_16 = 0 ;
V_13 -> V_18 = 0 ;
} else {
V_13 -> V_33 = V_14 ;
V_41 = V_1 -> V_43 = V_14 ;
}
}
}
V_1 -> V_10 = V_13 -> V_17 ;
F_14 ( & V_13 -> V_9 ) ;
return V_41 ;
}
int F_16 ( struct V_44 * V_44 , struct V_1 * V_1 )
{
struct V_4 * V_13 = V_1 -> V_6 ;
F_8 ( V_13 -> V_20 ) ;
F_8 ( V_13 ) ;
return 0 ;
}
int F_17 ( struct V_4 * V_13 , const char * V_45 , const char * V_46 )
{
char * V_47 = V_13 -> V_20 + V_13 -> V_21 ;
char * V_5 ;
char V_48 ;
for ( V_5 = V_13 -> V_20 + V_13 -> V_18 ; ( V_48 = * V_45 ) != '\0' && V_5 < V_47 ; V_45 ++ ) {
if ( ! strchr ( V_46 , V_48 ) ) {
* V_5 ++ = V_48 ;
continue;
}
if ( V_5 + 3 < V_47 ) {
* V_5 ++ = '\\' ;
* V_5 ++ = '0' + ( ( V_48 & 0300 ) >> 6 ) ;
* V_5 ++ = '0' + ( ( V_48 & 070 ) >> 3 ) ;
* V_5 ++ = '0' + ( V_48 & 07 ) ;
continue;
}
V_13 -> V_18 = V_13 -> V_21 ;
return - 1 ;
}
V_13 -> V_18 = V_5 - V_13 -> V_20 ;
return 0 ;
}
int F_18 ( struct V_4 * V_13 , const char * V_49 , ... )
{
T_5 args ;
int V_50 ;
if ( V_13 -> V_18 < V_13 -> V_21 ) {
va_start ( args , V_49 ) ;
V_50 = vsnprintf ( V_13 -> V_20 + V_13 -> V_18 , V_13 -> V_21 - V_13 -> V_18 , V_49 , args ) ;
va_end ( args ) ;
if ( V_13 -> V_18 + V_50 < V_13 -> V_21 ) {
V_13 -> V_18 += V_50 ;
return 0 ;
}
}
V_13 -> V_18 = V_13 -> V_21 ;
return - 1 ;
}
char * F_19 ( char * V_45 , char * V_5 , char * V_46 )
{
while ( V_45 <= V_5 ) {
char V_48 = * V_5 ++ ;
if ( ! V_48 ) {
return V_45 ;
} else if ( ! strchr ( V_46 , V_48 ) ) {
* V_45 ++ = V_48 ;
} else if ( V_45 + 4 > V_5 ) {
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
int F_20 ( struct V_4 * V_13 , struct V_51 * V_51 , char * V_46 )
{
char * V_20 ;
T_4 V_21 = F_21 ( V_13 , & V_20 ) ;
int V_52 = - 1 ;
if ( V_21 ) {
char * V_5 = F_22 ( V_51 , V_20 , V_21 ) ;
if ( ! F_6 ( V_5 ) ) {
char * V_47 = F_19 ( V_20 , V_5 , V_46 ) ;
if ( V_47 )
V_52 = V_47 - V_20 ;
}
}
F_23 ( V_13 , V_52 ) ;
return V_52 ;
}
int F_24 ( struct V_4 * V_13 , struct V_51 * V_51 , struct V_51 * V_53 ,
char * V_46 )
{
char * V_20 ;
T_4 V_21 = F_21 ( V_13 , & V_20 ) ;
int V_52 = - V_54 ;
if ( V_21 ) {
char * V_5 ;
V_5 = F_25 ( V_51 , V_53 , V_20 , V_21 ) ;
if ( ! V_5 )
return V_55 ;
V_52 = F_5 ( V_5 ) ;
if ( ! F_6 ( V_5 ) ) {
char * V_47 = F_19 ( V_20 , V_5 , V_46 ) ;
if ( V_47 )
V_52 = V_47 - V_20 ;
else
V_52 = - V_54 ;
}
}
F_23 ( V_13 , V_52 ) ;
return V_52 < 0 && V_52 != - V_54 ? V_52 : 0 ;
}
int F_26 ( struct V_4 * V_13 , struct V_56 * V_56 , char * V_46 )
{
char * V_20 ;
T_4 V_21 = F_21 ( V_13 , & V_20 ) ;
int V_52 = - 1 ;
if ( V_21 ) {
char * V_5 = F_27 ( V_56 , V_20 , V_21 ) ;
if ( ! F_6 ( V_5 ) ) {
char * V_47 = F_19 ( V_20 , V_5 , V_46 ) ;
if ( V_47 )
V_52 = V_47 - V_20 ;
}
}
F_23 ( V_13 , V_52 ) ;
return V_52 ;
}
int F_28 ( struct V_4 * V_13 , const unsigned long * V_57 ,
unsigned int V_58 )
{
if ( V_13 -> V_18 < V_13 -> V_21 ) {
int V_50 = F_29 ( V_13 -> V_20 + V_13 -> V_18 ,
V_13 -> V_21 - V_13 -> V_18 , V_57 , V_58 ) ;
if ( V_13 -> V_18 + V_50 < V_13 -> V_21 ) {
V_13 -> V_18 += V_50 ;
return 0 ;
}
}
V_13 -> V_18 = V_13 -> V_21 ;
return - 1 ;
}
int F_30 ( struct V_4 * V_13 , const unsigned long * V_57 ,
unsigned int V_58 )
{
if ( V_13 -> V_18 < V_13 -> V_21 ) {
int V_50 = F_31 ( V_13 -> V_20 + V_13 -> V_18 ,
V_13 -> V_21 - V_13 -> V_18 , V_57 , V_58 ) ;
if ( V_13 -> V_18 + V_50 < V_13 -> V_21 ) {
V_13 -> V_18 += V_50 ;
return 0 ;
}
}
V_13 -> V_18 = V_13 -> V_21 ;
return - 1 ;
}
static void * F_32 ( struct V_4 * V_5 , T_1 * V_15 )
{
return NULL + ( * V_15 == 0 ) ;
}
static void * F_33 ( struct V_4 * V_5 , void * V_59 , T_1 * V_15 )
{
++ * V_15 ;
return NULL ;
}
static void F_34 ( struct V_4 * V_5 , void * V_59 )
{
}
int F_35 ( struct V_1 * V_1 , int (* V_24)( struct V_4 * , void * ) ,
void * V_60 )
{
struct V_2 * V_3 = F_2 ( sizeof( * V_3 ) , V_7 ) ;
int V_52 = - V_8 ;
if ( V_3 ) {
V_3 -> V_23 = F_32 ;
V_3 -> V_26 = F_33 ;
V_3 -> V_27 = F_34 ;
V_3 -> V_24 = V_24 ;
V_52 = F_1 ( V_1 , V_3 ) ;
if ( ! V_52 )
( (struct V_4 * ) V_1 -> V_6 ) -> V_61 = V_60 ;
else
F_8 ( V_3 ) ;
}
return V_52 ;
}
int F_36 ( struct V_44 * V_44 , struct V_1 * V_1 )
{
const struct V_2 * V_3 = ( (struct V_4 * ) V_1 -> V_6 ) -> V_3 ;
int V_52 = F_16 ( V_44 , V_1 ) ;
F_8 ( V_3 ) ;
return V_52 ;
}
int F_37 ( struct V_44 * V_44 , struct V_1 * V_1 )
{
struct V_4 * V_62 = V_1 -> V_6 ;
F_8 ( V_62 -> V_61 ) ;
V_62 -> V_61 = NULL ;
return F_16 ( V_44 , V_1 ) ;
}
void * F_38 ( struct V_1 * V_49 , const struct V_2 * V_63 ,
int V_64 )
{
int V_65 ;
void * V_61 ;
struct V_4 * V_62 ;
V_61 = F_39 ( V_64 , V_7 ) ;
if ( V_61 == NULL )
goto V_66;
V_65 = F_1 ( V_49 , V_63 ) ;
if ( V_65 < 0 )
goto V_67;
V_62 = V_49 -> V_6 ;
V_62 -> V_61 = V_61 ;
return V_61 ;
V_67:
F_8 ( V_61 ) ;
V_66:
return NULL ;
}
int F_40 ( struct V_1 * V_68 , const struct V_2 * V_63 ,
int V_64 )
{
return F_38 ( V_68 , V_63 , V_64 ) ? 0 : - V_8 ;
}
int F_41 ( struct V_4 * V_13 , char V_48 )
{
if ( V_13 -> V_18 < V_13 -> V_21 ) {
V_13 -> V_20 [ V_13 -> V_18 ++ ] = V_48 ;
return 0 ;
}
return - 1 ;
}
int F_42 ( struct V_4 * V_13 , const char * V_45 )
{
int V_50 = strlen ( V_45 ) ;
if ( V_13 -> V_18 + V_50 < V_13 -> V_21 ) {
memcpy ( V_13 -> V_20 + V_13 -> V_18 , V_45 , V_50 ) ;
V_13 -> V_18 += V_50 ;
return 0 ;
}
V_13 -> V_18 = V_13 -> V_21 ;
return - 1 ;
}
int F_43 ( struct V_4 * V_62 , const void * V_60 , T_4 V_50 )
{
if ( V_62 -> V_18 + V_50 < V_62 -> V_21 ) {
memcpy ( V_62 -> V_20 + V_62 -> V_18 , V_60 , V_50 ) ;
V_62 -> V_18 += V_50 ;
return 0 ;
}
V_62 -> V_18 = V_62 -> V_21 ;
return - 1 ;
}
struct V_69 * F_44 ( struct V_69 * V_70 , T_1 V_15 )
{
struct V_69 * V_71 ;
F_45 (lh, head)
if ( V_15 -- == 0 )
return V_71 ;
return NULL ;
}
struct V_69 * F_46 ( struct V_69 * V_70 , T_1 V_15 )
{
if ( ! V_15 )
return V_70 ;
return F_44 ( V_70 , V_15 - 1 ) ;
}
struct V_69 * F_47 ( void * V_59 , struct V_69 * V_70 , T_1 * V_29 )
{
struct V_69 * V_71 ;
V_71 = ( (struct V_69 * ) V_59 ) -> V_26 ;
++ * V_29 ;
return V_71 == V_70 ? NULL : V_71 ;
}
struct V_72 * F_48 ( struct V_73 * V_70 , T_1 V_15 )
{
struct V_72 * V_74 ;
F_49 (node, head)
if ( V_15 -- == 0 )
return V_74 ;
return NULL ;
}
struct V_72 * F_50 ( struct V_73 * V_70 , T_1 V_15 )
{
if ( ! V_15 )
return V_75 ;
return F_48 ( V_70 , V_15 - 1 ) ;
}
struct V_72 * F_51 ( void * V_59 , struct V_73 * V_70 ,
T_1 * V_29 )
{
struct V_72 * V_74 = V_59 ;
++ * V_29 ;
if ( V_59 == V_75 )
return V_70 -> V_76 ;
else
return V_74 -> V_26 ;
}
struct V_72 * F_52 ( struct V_73 * V_70 ,
T_1 V_15 )
{
struct V_72 * V_74 ;
F_53 (node, head)
if ( V_15 -- == 0 )
return V_74 ;
return NULL ;
}
struct V_72 * F_54 ( struct V_73 * V_70 ,
T_1 V_15 )
{
if ( ! V_15 )
return V_75 ;
return F_52 ( V_70 , V_15 - 1 ) ;
}
struct V_72 * F_55 ( void * V_59 ,
struct V_73 * V_70 ,
T_1 * V_29 )
{
struct V_72 * V_74 = V_59 ;
++ * V_29 ;
if ( V_59 == V_75 )
return F_56 ( V_70 -> V_76 ) ;
else
return F_56 ( V_74 -> V_26 ) ;
}
