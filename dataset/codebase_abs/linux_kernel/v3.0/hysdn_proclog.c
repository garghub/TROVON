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
unsigned char V_38 [ 128 ] ;
T_1 * V_1 = V_34 -> V_39 ;
if ( V_35 > ( sizeof( V_38 ) - 1 ) )
V_35 = sizeof( V_38 ) - 1 ;
if ( F_11 ( V_38 , V_4 , V_35 ) )
return ( - V_40 ) ;
V_38 [ V_35 ] = 0 ;
V_37 = F_12 ( V_38 , 0 , & V_1 -> V_16 ) ;
if ( V_37 < 0 )
return V_37 ;
F_3 ( V_1 , L_4 , V_1 -> V_16 ) ;
return ( V_35 ) ;
}
static T_4
F_13 ( struct V_34 * V_34 , char T_5 * V_4 , T_6 V_35 , T_7 * V_36 )
{
struct V_19 * V_41 ;
int V_42 ;
struct V_43 * V_44 = F_14 ( V_34 -> V_45 . V_46 -> V_47 ) ;
struct V_10 * V_11 = NULL ;
T_1 * V_1 ;
if ( ! * ( (struct V_19 * * ) V_34 -> V_39 ) ) {
if ( V_34 -> V_48 & V_49 )
return ( - V_50 ) ;
V_1 = V_51 ;
while ( V_1 ) {
V_11 = V_1 -> V_12 ;
if ( V_11 -> log == V_44 )
break;
V_1 = V_1 -> V_26 ;
}
if ( V_1 )
F_15 ( & ( V_11 -> V_33 ) ) ;
else
return ( - V_50 ) ;
}
if ( ! ( V_41 = * ( (struct V_19 * * ) V_34 -> V_39 ) ) )
return ( 0 ) ;
V_41 -> V_29 -- ;
V_34 -> V_39 = & V_41 -> V_26 ;
if ( ( V_42 = strlen ( V_41 -> V_25 ) ) <= V_35 ) {
if ( F_16 ( V_4 , V_41 -> V_25 , V_42 ) )
return - V_40 ;
* V_36 += V_42 ;
return ( V_42 ) ;
}
return ( 0 ) ;
}
static int
F_17 ( struct V_52 * V_53 , struct V_34 * V_54 )
{
T_1 * V_1 ;
struct V_10 * V_11 = NULL ;
unsigned long V_22 ;
F_18 ( & V_55 ) ;
V_1 = V_51 ;
while ( V_1 ) {
V_11 = V_1 -> V_12 ;
if ( V_11 -> log == F_14 ( V_53 ) )
break;
V_1 = V_1 -> V_26 ;
}
if ( ! V_1 ) {
F_19 ( & V_55 ) ;
return ( - V_56 ) ;
}
V_54 -> V_39 = V_1 ;
if ( ( V_54 -> V_57 & ( V_58 | V_59 ) ) == V_59 ) {
} else if ( ( V_54 -> V_57 & ( V_58 | V_59 ) ) == V_58 ) {
F_6 ( & V_1 -> V_28 , V_22 ) ;
V_11 -> V_23 ++ ;
if ( V_11 -> V_30 )
V_54 -> V_39 = & V_11 -> V_31 -> V_26 ;
else
V_54 -> V_39 = & V_11 -> V_30 ;
F_7 ( & V_1 -> V_28 , V_22 ) ;
} else {
F_19 ( & V_55 ) ;
return ( - V_60 ) ;
}
F_19 ( & V_55 ) ;
return F_20 ( V_53 , V_54 ) ;
}
static int
F_21 ( struct V_52 * V_53 , struct V_34 * V_54 )
{
struct V_19 * V_41 ;
struct V_10 * V_11 ;
T_1 * V_1 ;
int V_61 = 0 ;
F_18 ( & V_55 ) ;
if ( ( V_54 -> V_57 & ( V_58 | V_59 ) ) == V_59 ) {
V_61 = 0 ;
} else {
V_11 = NULL ;
V_41 = * ( (struct V_19 * * ) V_54 -> V_39 ) ;
if ( V_41 )
V_11 = (struct V_10 * ) V_41 -> V_27 ;
else {
V_1 = V_51 ;
while ( V_1 ) {
V_11 = V_1 -> V_12 ;
if ( V_11 -> log == F_14 ( V_53 ) )
break;
V_1 = V_1 -> V_26 ;
}
if ( V_1 )
V_11 = V_1 -> V_12 ;
}
if ( V_11 )
V_11 -> V_23 -- ;
while ( V_41 ) {
V_41 -> V_29 -- ;
V_41 = V_41 -> V_26 ;
}
if ( V_11 )
if ( V_11 -> V_23 <= 0 )
while ( V_11 -> V_30 ) {
V_41 = V_11 -> V_30 ;
V_11 -> V_30 = V_11 -> V_30 -> V_26 ;
F_8 ( V_41 ) ;
}
}
F_19 ( & V_55 ) ;
return ( V_61 ) ;
}
static unsigned int
F_22 ( struct V_34 * V_34 , T_8 * V_62 )
{
unsigned int V_63 = 0 ;
struct V_43 * V_44 = F_14 ( V_34 -> V_45 . V_46 -> V_47 ) ;
T_1 * V_1 ;
struct V_10 * V_11 = NULL ;
if ( ( V_34 -> V_57 & ( V_58 | V_59 ) ) == V_59 )
return ( V_63 ) ;
V_1 = V_51 ;
while ( V_1 ) {
V_11 = V_1 -> V_12 ;
if ( V_11 -> log == V_44 )
break;
V_1 = V_1 -> V_26 ;
}
if ( ! V_1 )
return ( V_63 ) ;
F_23 ( V_34 , & ( V_11 -> V_33 ) , V_62 ) ;
if ( * ( (struct V_19 * * ) V_34 -> V_39 ) )
V_63 |= V_64 | V_65 ;
return V_63 ;
}
int
F_24 ( T_1 * V_1 )
{
struct V_10 * V_11 ;
if ( ( V_11 = F_25 ( sizeof( struct V_10 ) , V_66 ) ) != NULL ) {
sprintf ( V_11 -> V_67 , L_5 , V_68 , V_1 -> V_15 ) ;
V_11 -> log = F_26 ( V_11 -> V_67 ,
V_69 | V_70 | V_71 , V_72 ,
& V_73 ) ;
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
F_29 ( V_11 -> V_67 , V_72 ) ;
F_8 ( V_11 ) ;
V_1 -> V_12 = NULL ;
}
}
