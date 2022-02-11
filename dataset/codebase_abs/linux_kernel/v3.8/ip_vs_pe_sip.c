static const char * F_1 ( char * V_1 , T_1 V_2 ,
const char * V_3 , T_1 V_4 ,
int * V_5 )
{
T_1 V_6 = F_2 ( F_2 ( V_4 , ( T_1 ) 64 ) , V_2 - * V_5 - 1 ) ;
memcpy ( V_1 + * V_5 , V_3 , V_6 ) ;
V_1 [ * V_5 + V_6 ] = '\0' ;
* V_5 += V_6 + 1 ;
return V_1 + * V_5 - V_6 ;
}
static int F_3 ( const char * V_7 , unsigned int V_8 ,
unsigned int V_9 ,
unsigned int * V_10 , unsigned int * V_11 )
{
while ( 1 ) {
int V_12 = F_4 ( NULL , V_7 , V_8 , V_9 ,
V_13 , V_10 ,
V_11 ) ;
if ( V_12 > 0 )
break;
if ( ! V_12 )
return 0 ;
V_8 += * V_10 ;
}
if ( ! * V_11 )
return - V_14 ;
if ( * V_11 > V_15 )
return - V_14 ;
if ( * V_10 + * V_11 == V_9 )
return - V_14 ;
if ( * ( V_7 + * V_10 + * V_11 ) != '\r' &&
* ( V_7 + * V_10 + * V_11 ) != '\n' )
return - V_14 ;
F_5 ( 9 , L_1 ,
F_6 ( V_7 + * V_10 , * V_11 ) ,
* V_11 ) ;
return 0 ;
}
static int
F_7 ( struct V_16 * V_17 , struct V_18 * V_19 )
{
struct V_18 * V_20 = F_8 ( V_19 ) ;
struct V_21 V_22 ;
unsigned int V_8 , V_9 , V_10 , V_11 ;
const char * V_7 ;
int V_23 ;
F_9 ( V_17 -> V_24 , V_19 , & V_22 ) ;
if ( V_22 . V_25 != V_26 )
return - V_14 ;
if ( V_20 ) {
V_19 = V_20 ;
V_8 = V_22 . V_27 + sizeof( struct V_28 ) ;
} else
V_8 = V_22 . V_6 + sizeof( struct V_28 ) ;
if ( V_8 >= V_19 -> V_6 )
return - V_14 ;
V_23 = F_10 ( V_19 ) ;
if ( V_23 < 0 )
return V_23 ;
V_7 = V_19 -> V_29 + V_8 ;
V_9 = V_19 -> V_6 - V_8 ;
if ( F_3 ( V_7 , V_8 , V_9 , & V_10 , & V_11 ) )
return - V_14 ;
V_17 -> V_30 = F_11 ( V_7 + V_10 , V_11 , V_31 ) ;
if ( ! V_17 -> V_30 )
return - V_32 ;
V_17 -> V_33 = V_11 ;
return 0 ;
}
static bool F_12 ( const struct V_16 * V_17 ,
struct V_34 * V_35 )
{
bool V_12 = false ;
if ( V_35 -> V_24 == V_17 -> V_24 &&
F_13 ( V_17 -> V_24 , V_17 -> V_36 , & V_35 -> V_36 ) &&
F_13 ( V_17 -> V_25 == V_37 ? V_38 : V_17 -> V_24 ,
V_17 -> V_39 , & V_35 -> V_39 ) &&
V_35 -> V_40 == V_17 -> V_40 &&
V_35 -> V_41 & V_42 &&
V_35 -> V_25 == V_17 -> V_25 &&
V_35 -> V_30 && V_35 -> V_33 == V_17 -> V_33 &&
! memcmp ( V_35 -> V_30 , V_17 -> V_30 , V_17 -> V_33 ) )
V_12 = true ;
F_5 ( 9 , L_2 ,
F_14 ( V_17 -> V_25 ) ,
F_6 ( V_17 -> V_30 , V_17 -> V_33 ) ,
F_15 ( V_17 -> V_24 , V_17 -> V_39 ) , F_16 ( V_17 -> V_40 ) ,
V_12 ? L_3 : L_4 ) ;
return V_12 ;
}
static T_2 F_17 ( const struct V_16 * V_17 ,
T_2 V_43 , bool V_44 )
{
return F_18 ( V_17 -> V_30 , V_17 -> V_33 , V_43 ) ;
}
static int F_19 ( const struct V_34 * V_45 , char * V_1 )
{
memcpy ( V_1 , V_45 -> V_30 , V_45 -> V_33 ) ;
return V_45 -> V_33 ;
}
static int T_3 F_20 ( void )
{
return F_21 ( & V_46 ) ;
}
static void T_4 F_22 ( void )
{
F_23 ( & V_46 ) ;
}
