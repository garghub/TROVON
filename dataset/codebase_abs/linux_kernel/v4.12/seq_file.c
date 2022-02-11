static void F_1 ( struct V_1 * V_2 )
{
V_2 -> V_3 = V_2 -> V_4 ;
}
static void * F_2 ( unsigned long V_4 )
{
return F_3 ( V_4 , V_5 ) ;
}
int F_4 ( struct V_6 * V_6 , const struct V_7 * V_8 )
{
struct V_1 * V_9 ;
F_5 ( V_6 -> V_10 ) ;
V_9 = F_6 ( sizeof( * V_9 ) , V_5 ) ;
if ( ! V_9 )
return - V_11 ;
V_6 -> V_10 = V_9 ;
F_7 ( & V_9 -> V_12 ) ;
V_9 -> V_8 = V_8 ;
V_9 -> V_6 = V_6 ;
V_6 -> V_13 = 0 ;
V_6 -> V_14 &= ~ V_15 ;
return 0 ;
}
static int F_8 ( struct V_1 * V_2 , T_1 V_16 )
{
T_1 V_17 = 0 , V_18 ;
int error = 0 ;
void * V_9 ;
V_2 -> V_19 = 0 ;
V_18 = 0 ;
V_2 -> V_3 = V_2 -> V_20 = 0 ;
if ( ! V_16 ) {
V_2 -> V_18 = V_18 ;
return 0 ;
}
if ( ! V_2 -> V_21 ) {
V_2 -> V_21 = F_2 ( V_2 -> V_4 = V_22 ) ;
if ( ! V_2 -> V_21 )
return - V_11 ;
}
V_9 = V_2 -> V_8 -> V_23 ( V_2 , & V_18 ) ;
while ( V_9 ) {
error = F_9 ( V_9 ) ;
if ( F_10 ( V_9 ) )
break;
error = V_2 -> V_8 -> V_24 ( V_2 , V_9 ) ;
if ( error < 0 )
break;
if ( F_11 ( error ) ) {
error = 0 ;
V_2 -> V_3 = 0 ;
}
if ( F_12 ( V_2 ) )
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
V_9 = V_2 -> V_8 -> V_26 ( V_2 , V_9 , & V_18 ) ;
}
V_2 -> V_8 -> V_27 ( V_2 , V_9 ) ;
V_2 -> V_18 = V_18 ;
return error ;
V_25:
V_2 -> V_8 -> V_27 ( V_2 , V_9 ) ;
F_13 ( V_2 -> V_21 ) ;
V_2 -> V_3 = 0 ;
V_2 -> V_21 = F_2 ( V_2 -> V_4 <<= 1 ) ;
return ! V_2 -> V_21 ? - V_11 : - V_28 ;
}
T_2 F_14 ( struct V_6 * V_6 , char T_3 * V_21 , T_4 V_4 , T_1 * V_29 )
{
struct V_1 * V_2 = V_6 -> V_10 ;
T_4 V_30 = 0 ;
T_1 V_17 ;
T_4 V_31 ;
void * V_9 ;
int V_32 = 0 ;
F_15 ( & V_2 -> V_12 ) ;
V_2 -> V_19 = V_6 -> V_13 ;
if ( * V_29 == 0 )
V_2 -> V_18 = 0 ;
if ( F_11 ( * V_29 != V_2 -> V_33 ) ) {
while ( ( V_32 = F_8 ( V_2 , * V_29 ) ) == - V_28 )
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
V_2 -> V_21 = F_2 ( V_2 -> V_4 = V_22 ) ;
if ( ! V_2 -> V_21 )
goto V_35;
}
if ( V_2 -> V_3 ) {
V_31 = F_16 ( V_2 -> V_3 , V_4 ) ;
V_32 = F_17 ( V_21 , V_2 -> V_21 + V_2 -> V_20 , V_31 ) ;
if ( V_32 )
goto V_36;
V_2 -> V_3 -= V_31 ;
V_2 -> V_20 += V_31 ;
V_4 -= V_31 ;
V_21 += V_31 ;
V_30 += V_31 ;
if ( ! V_2 -> V_3 ) {
V_2 -> V_20 = 0 ;
V_2 -> V_18 ++ ;
}
if ( ! V_4 )
goto V_34;
}
V_17 = V_2 -> V_18 ;
V_9 = V_2 -> V_8 -> V_23 ( V_2 , & V_17 ) ;
while ( 1 ) {
V_32 = F_9 ( V_9 ) ;
if ( ! V_9 || F_10 ( V_9 ) )
break;
V_32 = V_2 -> V_8 -> V_24 ( V_2 , V_9 ) ;
if ( V_32 < 0 )
break;
if ( F_11 ( V_32 ) )
V_2 -> V_3 = 0 ;
if ( F_11 ( ! V_2 -> V_3 ) ) {
V_9 = V_2 -> V_8 -> V_26 ( V_2 , V_9 , & V_17 ) ;
V_2 -> V_18 = V_17 ;
continue;
}
if ( V_2 -> V_3 < V_2 -> V_4 )
goto V_37;
V_2 -> V_8 -> V_27 ( V_2 , V_9 ) ;
F_13 ( V_2 -> V_21 ) ;
V_2 -> V_3 = 0 ;
V_2 -> V_21 = F_2 ( V_2 -> V_4 <<= 1 ) ;
if ( ! V_2 -> V_21 )
goto V_35;
V_2 -> V_19 = 0 ;
V_17 = V_2 -> V_18 ;
V_9 = V_2 -> V_8 -> V_23 ( V_2 , & V_17 ) ;
}
V_2 -> V_8 -> V_27 ( V_2 , V_9 ) ;
V_2 -> V_3 = 0 ;
goto V_34;
V_37:
while ( V_2 -> V_3 < V_4 ) {
T_4 V_38 = V_2 -> V_3 ;
T_1 V_26 = V_17 ;
V_9 = V_2 -> V_8 -> V_26 ( V_2 , V_9 , & V_26 ) ;
if ( ! V_9 || F_10 ( V_9 ) ) {
V_32 = F_9 ( V_9 ) ;
break;
}
V_32 = V_2 -> V_8 -> V_24 ( V_2 , V_9 ) ;
if ( F_12 ( V_2 ) || V_32 ) {
V_2 -> V_3 = V_38 ;
if ( F_18 ( V_32 <= 0 ) )
break;
}
V_17 = V_26 ;
}
V_2 -> V_8 -> V_27 ( V_2 , V_9 ) ;
V_31 = F_16 ( V_2 -> V_3 , V_4 ) ;
V_32 = F_17 ( V_21 , V_2 -> V_21 , V_31 ) ;
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
V_6 -> V_13 = V_2 -> V_19 ;
F_19 ( & V_2 -> V_12 ) ;
return V_30 ;
V_35:
V_32 = - V_11 ;
goto V_34;
V_36:
V_32 = - V_39 ;
goto V_34;
}
T_1 F_20 ( struct V_6 * V_6 , T_1 V_16 , int V_40 )
{
struct V_1 * V_2 = V_6 -> V_10 ;
T_1 V_41 = - V_42 ;
F_15 ( & V_2 -> V_12 ) ;
V_2 -> V_19 = V_6 -> V_13 ;
switch ( V_40 ) {
case V_43 :
V_16 += V_6 -> V_44 ;
case V_45 :
if ( V_16 < 0 )
break;
V_41 = V_16 ;
if ( V_16 != V_2 -> V_33 ) {
while ( ( V_41 = F_8 ( V_2 , V_16 ) ) == - V_28 )
;
if ( V_41 ) {
V_6 -> V_44 = 0 ;
V_2 -> V_33 = 0 ;
V_2 -> V_19 = 0 ;
V_2 -> V_18 = 0 ;
V_2 -> V_3 = 0 ;
} else {
V_2 -> V_33 = V_16 ;
V_41 = V_6 -> V_44 = V_16 ;
}
} else {
V_6 -> V_44 = V_16 ;
}
}
V_6 -> V_13 = V_2 -> V_19 ;
F_19 ( & V_2 -> V_12 ) ;
return V_41 ;
}
int F_21 ( struct V_46 * V_46 , struct V_6 * V_6 )
{
struct V_1 * V_2 = V_6 -> V_10 ;
F_13 ( V_2 -> V_21 ) ;
F_22 ( V_2 ) ;
return 0 ;
}
void F_23 ( struct V_1 * V_2 , const char * V_47 , const char * V_48 )
{
char * V_21 ;
T_4 V_4 = F_24 ( V_2 , & V_21 ) ;
int V_49 ;
V_49 = F_25 ( V_47 , V_21 , V_4 , V_50 , V_48 ) ;
F_26 ( V_2 , V_49 < V_4 ? V_49 : - 1 ) ;
}
void F_27 ( struct V_1 * V_2 , const char * V_51 , T_5 args )
{
int V_52 ;
if ( V_2 -> V_3 < V_2 -> V_4 ) {
V_52 = vsnprintf ( V_2 -> V_21 + V_2 -> V_3 , V_2 -> V_4 - V_2 -> V_3 , V_51 , args ) ;
if ( V_2 -> V_3 + V_52 < V_2 -> V_4 ) {
V_2 -> V_3 += V_52 ;
return;
}
}
F_1 ( V_2 ) ;
}
void F_28 ( struct V_1 * V_2 , const char * V_51 , ... )
{
T_5 args ;
va_start ( args , V_51 ) ;
F_27 ( V_2 , V_51 , args ) ;
va_end ( args ) ;
}
char * F_29 ( char * V_47 , const char * V_9 , const char * V_48 )
{
while ( V_47 <= V_9 ) {
char V_53 = * V_9 ++ ;
if ( ! V_53 ) {
return V_47 ;
} else if ( ! strchr ( V_48 , V_53 ) ) {
* V_47 ++ = V_53 ;
} else if ( V_47 + 4 > V_9 ) {
break;
} else {
* V_47 ++ = '\\' ;
* V_47 ++ = '0' + ( ( V_53 & 0300 ) >> 6 ) ;
* V_47 ++ = '0' + ( ( V_53 & 070 ) >> 3 ) ;
* V_47 ++ = '0' + ( V_53 & 07 ) ;
}
}
return NULL ;
}
int F_30 ( struct V_1 * V_2 , const struct V_54 * V_54 , const char * V_48 )
{
char * V_21 ;
T_4 V_4 = F_24 ( V_2 , & V_21 ) ;
int V_55 = - 1 ;
if ( V_4 ) {
char * V_9 = F_31 ( V_54 , V_21 , V_4 ) ;
if ( ! F_10 ( V_9 ) ) {
char * V_56 = F_29 ( V_21 , V_9 , V_48 ) ;
if ( V_56 )
V_55 = V_56 - V_21 ;
}
}
F_26 ( V_2 , V_55 ) ;
return V_55 ;
}
int F_32 ( struct V_1 * V_2 , struct V_6 * V_6 , const char * V_48 )
{
return F_30 ( V_2 , & V_6 -> V_57 , V_48 ) ;
}
int F_33 ( struct V_1 * V_2 , const struct V_54 * V_54 ,
const struct V_54 * V_58 , const char * V_48 )
{
char * V_21 ;
T_4 V_4 = F_24 ( V_2 , & V_21 ) ;
int V_55 = - V_59 ;
if ( V_4 ) {
char * V_9 ;
V_9 = F_34 ( V_54 , V_58 , V_21 , V_4 ) ;
if ( ! V_9 )
return V_60 ;
V_55 = F_9 ( V_9 ) ;
if ( ! F_10 ( V_9 ) ) {
char * V_56 = F_29 ( V_21 , V_9 , V_48 ) ;
if ( V_56 )
V_55 = V_56 - V_21 ;
else
V_55 = - V_59 ;
}
}
F_26 ( V_2 , V_55 ) ;
return V_55 < 0 && V_55 != - V_59 ? V_55 : 0 ;
}
int F_35 ( struct V_1 * V_2 , struct V_61 * V_61 , const char * V_48 )
{
char * V_21 ;
T_4 V_4 = F_24 ( V_2 , & V_21 ) ;
int V_55 = - 1 ;
if ( V_4 ) {
char * V_9 = F_36 ( V_61 , V_21 , V_4 ) ;
if ( ! F_10 ( V_9 ) ) {
char * V_56 = F_29 ( V_21 , V_9 , V_48 ) ;
if ( V_56 )
V_55 = V_56 - V_21 ;
}
}
F_26 ( V_2 , V_55 ) ;
return V_55 ;
}
static void * F_37 ( struct V_1 * V_9 , T_1 * V_17 )
{
return NULL + ( * V_17 == 0 ) ;
}
static void * F_38 ( struct V_1 * V_9 , void * V_62 , T_1 * V_17 )
{
++ * V_17 ;
return NULL ;
}
static void F_39 ( struct V_1 * V_9 , void * V_62 )
{
}
int F_40 ( struct V_6 * V_6 , int (* V_24)( struct V_1 * , void * ) ,
void * V_63 )
{
struct V_7 * V_8 = F_41 ( sizeof( * V_8 ) , V_5 ) ;
int V_55 = - V_11 ;
if ( V_8 ) {
V_8 -> V_23 = F_37 ;
V_8 -> V_26 = F_38 ;
V_8 -> V_27 = F_39 ;
V_8 -> V_24 = V_24 ;
V_55 = F_4 ( V_6 , V_8 ) ;
if ( ! V_55 )
( (struct V_1 * ) V_6 -> V_10 ) -> V_64 = V_63 ;
else
F_22 ( V_8 ) ;
}
return V_55 ;
}
int F_42 ( struct V_6 * V_6 , int (* V_24)( struct V_1 * , void * ) ,
void * V_63 , T_4 V_4 )
{
char * V_21 = F_2 ( V_4 ) ;
int V_49 ;
if ( ! V_21 )
return - V_11 ;
V_49 = F_40 ( V_6 , V_24 , V_63 ) ;
if ( V_49 ) {
F_13 ( V_21 ) ;
return V_49 ;
}
( (struct V_1 * ) V_6 -> V_10 ) -> V_21 = V_21 ;
( (struct V_1 * ) V_6 -> V_10 ) -> V_4 = V_4 ;
return 0 ;
}
int F_43 ( struct V_46 * V_46 , struct V_6 * V_6 )
{
const struct V_7 * V_8 = ( (struct V_1 * ) V_6 -> V_10 ) -> V_8 ;
int V_55 = F_21 ( V_46 , V_6 ) ;
F_22 ( V_8 ) ;
return V_55 ;
}
int F_44 ( struct V_46 * V_46 , struct V_6 * V_6 )
{
struct V_1 * V_65 = V_6 -> V_10 ;
F_22 ( V_65 -> V_64 ) ;
V_65 -> V_64 = NULL ;
return F_21 ( V_46 , V_6 ) ;
}
void * F_45 ( struct V_6 * V_51 , const struct V_7 * V_66 ,
int V_67 )
{
int V_68 ;
void * V_64 ;
struct V_1 * V_65 ;
V_64 = F_6 ( V_67 , V_5 ) ;
if ( V_64 == NULL )
goto V_69;
V_68 = F_4 ( V_51 , V_66 ) ;
if ( V_68 < 0 )
goto V_70;
V_65 = V_51 -> V_10 ;
V_65 -> V_64 = V_64 ;
return V_64 ;
V_70:
F_22 ( V_64 ) ;
V_69:
return NULL ;
}
int F_46 ( struct V_6 * V_71 , const struct V_7 * V_66 ,
int V_67 )
{
return F_45 ( V_71 , V_66 , V_67 ) ? 0 : - V_11 ;
}
void F_47 ( struct V_1 * V_2 , char V_53 )
{
if ( V_2 -> V_3 >= V_2 -> V_4 )
return;
V_2 -> V_21 [ V_2 -> V_3 ++ ] = V_53 ;
}
void F_48 ( struct V_1 * V_2 , const char * V_47 )
{
int V_52 = strlen ( V_47 ) ;
if ( V_2 -> V_3 + V_52 >= V_2 -> V_4 ) {
F_1 ( V_2 ) ;
return;
}
memcpy ( V_2 -> V_21 + V_2 -> V_3 , V_47 , V_52 ) ;
V_2 -> V_3 += V_52 ;
}
void F_49 ( struct V_1 * V_2 , const char * V_72 ,
unsigned long long V_73 )
{
int V_52 ;
if ( V_2 -> V_3 + 2 >= V_2 -> V_4 )
goto V_74;
V_52 = strlen ( V_72 ) ;
if ( V_2 -> V_3 + V_52 >= V_2 -> V_4 )
goto V_74;
memcpy ( V_2 -> V_21 + V_2 -> V_3 , V_72 , V_52 ) ;
V_2 -> V_3 += V_52 ;
if ( V_2 -> V_3 + 1 >= V_2 -> V_4 )
goto V_74;
if ( V_73 < 10 ) {
V_2 -> V_21 [ V_2 -> V_3 ++ ] = V_73 + '0' ;
return;
}
V_52 = F_50 ( V_2 -> V_21 + V_2 -> V_3 , V_2 -> V_4 - V_2 -> V_3 , V_73 ) ;
if ( ! V_52 )
goto V_74;
V_2 -> V_3 += V_52 ;
return;
V_74:
F_1 ( V_2 ) ;
}
void F_51 ( struct V_1 * V_2 , const char * V_72 , long long V_73 )
{
int V_52 ;
if ( V_2 -> V_3 + 3 >= V_2 -> V_4 )
goto V_74;
V_52 = strlen ( V_72 ) ;
if ( V_2 -> V_3 + V_52 >= V_2 -> V_4 )
goto V_74;
memcpy ( V_2 -> V_21 + V_2 -> V_3 , V_72 , V_52 ) ;
V_2 -> V_3 += V_52 ;
if ( V_2 -> V_3 + 2 >= V_2 -> V_4 )
goto V_74;
if ( V_73 < 0 ) {
V_2 -> V_21 [ V_2 -> V_3 ++ ] = '-' ;
V_73 = - V_73 ;
}
if ( V_73 < 10 ) {
V_2 -> V_21 [ V_2 -> V_3 ++ ] = V_73 + '0' ;
return;
}
V_52 = F_50 ( V_2 -> V_21 + V_2 -> V_3 , V_2 -> V_4 - V_2 -> V_3 , V_73 ) ;
if ( ! V_52 )
goto V_74;
V_2 -> V_3 += V_52 ;
return;
V_74:
F_1 ( V_2 ) ;
}
int F_52 ( struct V_1 * V_65 , const void * V_63 , T_4 V_52 )
{
if ( V_65 -> V_3 + V_52 < V_65 -> V_4 ) {
memcpy ( V_65 -> V_21 + V_65 -> V_3 , V_63 , V_52 ) ;
V_65 -> V_3 += V_52 ;
return 0 ;
}
F_1 ( V_65 ) ;
return - 1 ;
}
void F_53 ( struct V_1 * V_2 , char V_53 )
{
int V_4 = V_2 -> V_75 - V_2 -> V_3 ;
if ( V_4 > 0 )
F_28 ( V_2 , L_1 , V_4 , L_2 ) ;
if ( V_53 )
F_47 ( V_2 , V_53 ) ;
}
void F_54 ( struct V_1 * V_2 , const char * V_76 , int V_77 ,
int V_78 , int V_79 , const void * V_21 , T_4 V_52 ,
bool V_80 )
{
const T_6 * V_81 = V_21 ;
int V_82 , V_83 , V_84 = V_52 ;
char * V_85 ;
T_4 V_4 ;
int V_49 ;
if ( V_78 != 16 && V_78 != 32 )
V_78 = 16 ;
for ( V_82 = 0 ; V_82 < V_52 && ! F_12 ( V_2 ) ; V_82 += V_78 ) {
V_83 = F_16 ( V_84 , V_78 ) ;
V_84 -= V_78 ;
switch ( V_77 ) {
case V_86 :
F_28 ( V_2 , L_3 , V_76 , V_81 + V_82 ) ;
break;
case V_87 :
F_28 ( V_2 , L_4 , V_76 , V_82 ) ;
break;
default:
F_28 ( V_2 , L_5 , V_76 ) ;
break;
}
V_4 = F_24 ( V_2 , & V_85 ) ;
V_49 = F_55 ( V_81 + V_82 , V_83 , V_78 , V_79 ,
V_85 , V_4 , V_80 ) ;
F_26 ( V_2 , V_49 < V_4 ? V_49 : - 1 ) ;
F_47 ( V_2 , '\n' ) ;
}
}
struct V_88 * F_56 ( struct V_88 * V_89 , T_1 V_17 )
{
struct V_88 * V_90 ;
F_57 (lh, head)
if ( V_17 -- == 0 )
return V_90 ;
return NULL ;
}
struct V_88 * F_58 ( struct V_88 * V_89 , T_1 V_17 )
{
if ( ! V_17 )
return V_89 ;
return F_56 ( V_89 , V_17 - 1 ) ;
}
struct V_88 * F_59 ( void * V_62 , struct V_88 * V_89 , T_1 * V_29 )
{
struct V_88 * V_90 ;
V_90 = ( (struct V_88 * ) V_62 ) -> V_26 ;
++ * V_29 ;
return V_90 == V_89 ? NULL : V_90 ;
}
struct V_91 * F_60 ( struct V_92 * V_89 , T_1 V_17 )
{
struct V_91 * V_93 ;
F_61 (node, head)
if ( V_17 -- == 0 )
return V_93 ;
return NULL ;
}
struct V_91 * F_62 ( struct V_92 * V_89 , T_1 V_17 )
{
if ( ! V_17 )
return V_94 ;
return F_60 ( V_89 , V_17 - 1 ) ;
}
struct V_91 * F_63 ( void * V_62 , struct V_92 * V_89 ,
T_1 * V_29 )
{
struct V_91 * V_93 = V_62 ;
++ * V_29 ;
if ( V_62 == V_94 )
return V_89 -> V_95 ;
else
return V_93 -> V_26 ;
}
struct V_91 * F_64 ( struct V_92 * V_89 ,
T_1 V_17 )
{
struct V_91 * V_93 ;
F_65 (node, head)
if ( V_17 -- == 0 )
return V_93 ;
return NULL ;
}
struct V_91 * F_66 ( struct V_92 * V_89 ,
T_1 V_17 )
{
if ( ! V_17 )
return V_94 ;
return F_64 ( V_89 , V_17 - 1 ) ;
}
struct V_91 * F_67 ( void * V_62 ,
struct V_92 * V_89 ,
T_1 * V_29 )
{
struct V_91 * V_93 = V_62 ;
++ * V_29 ;
if ( V_62 == V_94 )
return F_68 ( V_89 -> V_95 ) ;
else
return F_68 ( V_93 -> V_26 ) ;
}
struct V_91 *
F_69 ( struct V_92 T_7 * V_89 , int * V_96 , T_1 V_17 )
{
struct V_91 * V_93 ;
F_70 (*cpu) {
F_61 (node, per_cpu_ptr(head, *cpu)) {
if ( V_17 -- == 0 )
return V_93 ;
}
}
return NULL ;
}
struct V_91 *
F_71 ( void * V_62 , struct V_92 T_7 * V_89 ,
int * V_96 , T_1 * V_17 )
{
struct V_91 * V_93 = V_62 ;
++ * V_17 ;
if ( V_93 -> V_26 )
return V_93 -> V_26 ;
for ( * V_96 = F_72 ( * V_96 , V_97 ) ; * V_96 < V_98 ;
* V_96 = F_72 ( * V_96 , V_97 ) ) {
struct V_92 * V_99 = F_73 ( V_89 , * V_96 ) ;
if ( ! F_74 ( V_99 ) )
return V_99 -> V_95 ;
}
return NULL ;
}
