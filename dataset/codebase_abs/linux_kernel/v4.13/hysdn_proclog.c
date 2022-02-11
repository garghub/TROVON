void
F_1 ( T_1 * V_1 , T_2 * V_2 , int V_3 )
{
char V_4 [ V_5 + 40 ] ;
sprintf ( V_4 , L_1 , V_2 -> V_6 , V_2 -> V_7 , V_2 -> V_8 ) ;
F_2 ( V_1 , V_4 ) ;
}
void
F_3 ( T_1 * V_1 , char * V_9 , ... )
{
struct V_10 * V_11 = V_1 -> V_12 ;
char * V_13 ;
T_3 args ;
if ( ! V_11 )
return;
V_13 = V_11 -> V_14 ;
V_13 += sprintf ( V_13 , L_2 , V_1 -> V_15 ) ;
va_start ( args , V_9 ) ;
V_13 += vsprintf ( V_13 , V_9 , args ) ;
va_end ( args ) ;
* V_13 ++ = '\n' ;
* V_13 = 0 ;
if ( V_1 -> V_16 & V_17 )
F_4 ( V_18 L_3 , V_11 -> V_14 ) ;
else
F_2 ( V_1 , V_11 -> V_14 ) ;
}
static void
F_2 ( T_1 * V_1 , char * V_13 )
{
struct V_19 * V_20 ;
struct V_10 * V_11 = V_1 -> V_12 ;
unsigned long V_21 ;
if ( ! V_11 )
return;
if ( ! V_13 )
return;
if ( ! * V_13 )
return;
if ( V_11 -> V_22 <= 0 )
return;
if ( ! ( V_20 = F_5 ( sizeof( struct V_19 ) + strlen ( V_13 ) , V_23 ) ) )
return;
strcpy ( V_20 -> V_24 , V_13 ) ;
V_20 -> V_25 = NULL ;
V_20 -> V_26 = V_11 ;
F_6 ( & V_1 -> V_27 , V_21 ) ;
V_20 -> V_28 = V_11 -> V_22 ;
if ( ! V_11 -> V_29 )
V_11 -> V_29 = V_20 ;
else
V_11 -> V_30 -> V_25 = V_20 ;
V_11 -> V_30 = V_20 ;
while ( V_11 -> V_29 -> V_25 ) {
if ( ( V_11 -> V_29 -> V_28 <= 0 ) &&
( V_11 -> V_29 -> V_25 -> V_28 <= 0 ) ) {
V_20 = V_11 -> V_29 ;
V_11 -> V_29 = V_11 -> V_29 -> V_25 ;
F_7 ( V_20 ) ;
} else {
break;
}
}
F_8 ( & V_1 -> V_27 , V_21 ) ;
F_9 ( & ( V_11 -> V_31 ) ) ;
}
static T_4
F_10 ( struct V_32 * V_32 , const char T_5 * V_4 , T_6 V_33 , T_7 * V_34 )
{
int V_35 ;
T_1 * V_1 = V_32 -> V_36 ;
V_35 = F_11 ( V_4 , V_33 , 0 , & V_1 -> V_16 ) ;
if ( V_35 < 0 )
return V_35 ;
F_3 ( V_1 , L_4 , V_1 -> V_16 ) ;
return ( V_33 ) ;
}
static T_4
F_12 ( struct V_32 * V_32 , char T_5 * V_4 , T_6 V_33 , T_7 * V_34 )
{
struct V_19 * V_37 ;
int V_38 ;
T_1 * V_1 = F_13 ( F_14 ( V_32 ) ) ;
if ( ! ( V_37 = * ( (struct V_19 * * ) V_32 -> V_36 ) ) ) {
struct V_10 * V_11 = V_1 -> V_12 ;
if ( V_32 -> V_39 & V_40 )
return ( - V_41 ) ;
F_15 ( V_11 -> V_31 , ( V_37 =
* ( (struct V_19 * * ) V_32 -> V_36 ) ) ) ;
}
if ( ! V_37 )
return ( 0 ) ;
V_37 -> V_28 -- ;
V_32 -> V_36 = & V_37 -> V_25 ;
if ( ( V_38 = strlen ( V_37 -> V_24 ) ) <= V_33 ) {
if ( F_16 ( V_4 , V_37 -> V_24 , V_38 ) )
return - V_42 ;
* V_34 += V_38 ;
return ( V_38 ) ;
}
return ( 0 ) ;
}
static int
F_17 ( struct V_43 * V_44 , struct V_32 * V_45 )
{
T_1 * V_1 = F_13 ( V_44 ) ;
F_18 ( & V_46 ) ;
if ( ( V_45 -> V_47 & ( V_48 | V_49 ) ) == V_49 ) {
V_45 -> V_36 = V_1 ;
} else if ( ( V_45 -> V_47 & ( V_48 | V_49 ) ) == V_48 ) {
struct V_10 * V_11 = V_1 -> V_12 ;
unsigned long V_21 ;
F_6 ( & V_1 -> V_27 , V_21 ) ;
V_11 -> V_22 ++ ;
if ( V_11 -> V_29 )
V_45 -> V_36 = & V_11 -> V_30 -> V_25 ;
else
V_45 -> V_36 = & V_11 -> V_29 ;
F_8 ( & V_1 -> V_27 , V_21 ) ;
} else {
F_19 ( & V_46 ) ;
return ( - V_50 ) ;
}
F_19 ( & V_46 ) ;
return F_20 ( V_44 , V_45 ) ;
}
static int
F_21 ( struct V_43 * V_44 , struct V_32 * V_45 )
{
struct V_19 * V_37 ;
struct V_10 * V_11 ;
T_1 * V_1 ;
int V_51 = 0 ;
F_18 ( & V_46 ) ;
if ( ( V_45 -> V_47 & ( V_48 | V_49 ) ) == V_49 ) {
V_51 = 0 ;
} else {
V_37 = * ( (struct V_19 * * ) V_45 -> V_36 ) ;
if ( V_37 )
V_11 = (struct V_10 * ) V_37 -> V_26 ;
else {
V_1 = F_13 ( F_14 ( V_45 ) ) ;
V_11 = V_1 -> V_12 ;
}
if ( V_11 )
V_11 -> V_22 -- ;
while ( V_37 ) {
V_37 -> V_28 -- ;
V_37 = V_37 -> V_25 ;
}
if ( V_11 )
if ( V_11 -> V_22 <= 0 )
while ( V_11 -> V_29 ) {
V_37 = V_11 -> V_29 ;
V_11 -> V_29 = V_11 -> V_29 -> V_25 ;
F_7 ( V_37 ) ;
}
}
F_19 ( & V_46 ) ;
return ( V_51 ) ;
}
static unsigned int
F_22 ( struct V_32 * V_32 , T_8 * V_52 )
{
unsigned int V_53 = 0 ;
T_1 * V_1 = F_13 ( F_14 ( V_32 ) ) ;
struct V_10 * V_11 = V_1 -> V_12 ;
if ( ( V_32 -> V_47 & ( V_48 | V_49 ) ) == V_49 )
return ( V_53 ) ;
F_23 ( V_32 , & ( V_11 -> V_31 ) , V_52 ) ;
if ( * ( (struct V_19 * * ) V_32 -> V_36 ) )
V_53 |= V_54 | V_55 ;
return V_53 ;
}
int
F_24 ( T_1 * V_1 )
{
struct V_10 * V_11 ;
if ( ( V_11 = F_25 ( sizeof( struct V_10 ) , V_56 ) ) != NULL ) {
sprintf ( V_11 -> V_57 , L_5 , V_58 , V_1 -> V_15 ) ;
V_11 -> log = F_26 ( V_11 -> V_57 ,
V_59 | V_60 | V_61 , V_62 ,
& V_63 , V_1 ) ;
F_27 ( & ( V_11 -> V_31 ) ) ;
V_1 -> V_12 = ( void * ) V_11 ;
}
return ( 0 ) ;
}
void
F_28 ( T_1 * V_1 )
{
struct V_10 * V_11 ;
if ( ( V_11 = (struct V_10 * ) V_1 -> V_12 ) != NULL ) {
if ( V_11 -> log )
F_29 ( V_11 -> V_57 , V_62 ) ;
F_7 ( V_11 ) ;
V_1 -> V_12 = NULL ;
}
}
