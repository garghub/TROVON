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
int V_21 ;
unsigned long V_22 ;
if ( ! V_11 )
return;
if ( ! V_13 )
return;
if ( ! * V_13 )
return;
if ( V_11 -> V_23 <= 0 )
return;
if ( ! ( V_20 = F_5 ( sizeof( struct V_19 ) + strlen ( V_13 ) , V_24 ) ) )
return;
strcpy ( V_20 -> V_25 , V_13 ) ;
V_20 -> V_26 = NULL ;
V_20 -> V_27 = V_11 ;
F_6 ( & V_1 -> V_28 , V_22 ) ;
V_20 -> V_29 = V_11 -> V_23 ;
if ( ! V_11 -> V_30 )
V_11 -> V_30 = V_20 ;
else
V_11 -> V_31 -> V_26 = V_20 ;
V_11 -> V_31 = V_20 ;
V_21 = V_11 -> V_32 ++ ;
F_7 ( & V_1 -> V_28 , V_22 ) ;
if ( ! V_21 )
while ( V_11 -> V_30 -> V_26 ) {
if ( ( V_11 -> V_30 -> V_29 <= 0 ) &&
( V_11 -> V_30 -> V_26 -> V_29 <= 0 ) ) {
V_20 = V_11 -> V_30 ;
V_11 -> V_30 = V_11 -> V_30 -> V_26 ;
F_8 ( V_20 ) ;
} else
break;
}
V_11 -> V_32 -- ;
F_9 ( & ( V_11 -> V_33 ) ) ;
}
static T_4
F_10 ( struct V_34 * V_34 , const char T_5 * V_4 , T_6 V_35 , T_7 * V_36 )
{
int V_37 ;
T_1 * V_1 = V_34 -> V_38 ;
V_37 = F_11 ( V_4 , V_35 , 0 , & V_1 -> V_16 ) ;
if ( V_37 < 0 )
return V_37 ;
F_3 ( V_1 , L_4 , V_1 -> V_16 ) ;
return ( V_35 ) ;
}
static T_4
F_12 ( struct V_34 * V_34 , char T_5 * V_4 , T_6 V_35 , T_7 * V_36 )
{
struct V_19 * V_39 ;
int V_40 ;
T_1 * V_1 = F_13 ( F_14 ( V_34 ) ) ;
if ( ! * ( (struct V_19 * * ) V_34 -> V_38 ) ) {
struct V_10 * V_11 = V_1 -> V_12 ;
if ( V_34 -> V_41 & V_42 )
return ( - V_43 ) ;
F_15 ( & ( V_11 -> V_33 ) ) ;
}
if ( ! ( V_39 = * ( (struct V_19 * * ) V_34 -> V_38 ) ) )
return ( 0 ) ;
V_39 -> V_29 -- ;
V_34 -> V_38 = & V_39 -> V_26 ;
if ( ( V_40 = strlen ( V_39 -> V_25 ) ) <= V_35 ) {
if ( F_16 ( V_4 , V_39 -> V_25 , V_40 ) )
return - V_44 ;
* V_36 += V_40 ;
return ( V_40 ) ;
}
return ( 0 ) ;
}
static int
F_17 ( struct V_45 * V_46 , struct V_34 * V_47 )
{
T_1 * V_1 = F_13 ( V_46 ) ;
F_18 ( & V_48 ) ;
if ( ( V_47 -> V_49 & ( V_50 | V_51 ) ) == V_51 ) {
V_47 -> V_38 = V_1 ;
} else if ( ( V_47 -> V_49 & ( V_50 | V_51 ) ) == V_50 ) {
struct V_10 * V_11 = V_1 -> V_12 ;
unsigned long V_22 ;
F_6 ( & V_1 -> V_28 , V_22 ) ;
V_11 -> V_23 ++ ;
if ( V_11 -> V_30 )
V_47 -> V_38 = & V_11 -> V_31 -> V_26 ;
else
V_47 -> V_38 = & V_11 -> V_30 ;
F_7 ( & V_1 -> V_28 , V_22 ) ;
} else {
F_19 ( & V_48 ) ;
return ( - V_52 ) ;
}
F_19 ( & V_48 ) ;
return F_20 ( V_46 , V_47 ) ;
}
static int
F_21 ( struct V_45 * V_46 , struct V_34 * V_47 )
{
struct V_19 * V_39 ;
struct V_10 * V_11 ;
T_1 * V_1 ;
int V_53 = 0 ;
F_18 ( & V_48 ) ;
if ( ( V_47 -> V_49 & ( V_50 | V_51 ) ) == V_51 ) {
V_53 = 0 ;
} else {
V_39 = * ( (struct V_19 * * ) V_47 -> V_38 ) ;
if ( V_39 )
V_11 = (struct V_10 * ) V_39 -> V_27 ;
else {
V_1 = F_13 ( F_14 ( V_47 ) ) ;
V_11 = V_1 -> V_12 ;
}
if ( V_11 )
V_11 -> V_23 -- ;
while ( V_39 ) {
V_39 -> V_29 -- ;
V_39 = V_39 -> V_26 ;
}
if ( V_11 )
if ( V_11 -> V_23 <= 0 )
while ( V_11 -> V_30 ) {
V_39 = V_11 -> V_30 ;
V_11 -> V_30 = V_11 -> V_30 -> V_26 ;
F_8 ( V_39 ) ;
}
}
F_19 ( & V_48 ) ;
return ( V_53 ) ;
}
static unsigned int
F_22 ( struct V_34 * V_34 , T_8 * V_54 )
{
unsigned int V_55 = 0 ;
T_1 * V_1 = F_13 ( F_14 ( V_34 ) ) ;
struct V_10 * V_11 = V_1 -> V_12 ;
if ( ( V_34 -> V_49 & ( V_50 | V_51 ) ) == V_51 )
return ( V_55 ) ;
F_23 ( V_34 , & ( V_11 -> V_33 ) , V_54 ) ;
if ( * ( (struct V_19 * * ) V_34 -> V_38 ) )
V_55 |= V_56 | V_57 ;
return V_55 ;
}
int
F_24 ( T_1 * V_1 )
{
struct V_10 * V_11 ;
if ( ( V_11 = F_25 ( sizeof( struct V_10 ) , V_58 ) ) != NULL ) {
sprintf ( V_11 -> V_59 , L_5 , V_60 , V_1 -> V_15 ) ;
V_11 -> log = F_26 ( V_11 -> V_59 ,
V_61 | V_62 | V_63 , V_64 ,
& V_65 , V_1 ) ;
F_27 ( & ( V_11 -> V_33 ) ) ;
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
F_29 ( V_11 -> V_59 , V_64 ) ;
F_8 ( V_11 ) ;
V_1 -> V_12 = NULL ;
}
}
