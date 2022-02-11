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
struct V_20 V_21 ;
unsigned int V_8 , V_9 , V_10 , V_11 ;
const char * V_7 ;
int V_22 ;
F_8 ( V_17 -> V_23 , F_9 ( V_19 ) , & V_21 ) ;
if ( V_21 . V_24 != V_25 )
return - V_14 ;
V_8 = V_21 . V_6 + sizeof( struct V_26 ) ;
if ( V_8 >= V_19 -> V_6 )
return - V_14 ;
if ( ( V_22 = F_10 ( V_19 ) ) < 0 )
return V_22 ;
V_7 = V_19 -> V_27 + V_8 ;
V_9 = V_19 -> V_6 - V_8 ;
if ( F_3 ( V_7 , V_8 , V_9 , & V_10 , & V_11 ) )
return - V_14 ;
V_17 -> V_28 = F_11 ( V_7 + V_10 , V_11 , V_29 ) ;
if ( ! V_17 -> V_28 )
return - V_30 ;
V_17 -> V_31 = V_11 ;
return 0 ;
}
static bool F_12 ( const struct V_16 * V_17 ,
struct V_32 * V_33 )
{
bool V_12 = 0 ;
if ( V_33 -> V_23 == V_17 -> V_23 &&
F_13 ( V_17 -> V_23 , V_17 -> V_34 , & V_33 -> V_34 ) &&
F_13 ( V_17 -> V_24 == V_35 ? V_36 : V_17 -> V_23 ,
V_17 -> V_37 , & V_33 -> V_37 ) &&
V_33 -> V_38 == V_17 -> V_38 &&
V_33 -> V_39 & V_40 &&
V_33 -> V_24 == V_17 -> V_24 &&
V_33 -> V_28 && V_33 -> V_31 == V_17 -> V_31 &&
! memcmp ( V_33 -> V_28 , V_17 -> V_28 , V_17 -> V_31 ) )
V_12 = 1 ;
F_5 ( 9 , L_2 ,
F_14 ( V_17 -> V_24 ) ,
F_6 ( V_17 -> V_28 , V_17 -> V_31 ) ,
F_15 ( V_17 -> V_23 , V_17 -> V_37 ) , F_16 ( V_17 -> V_38 ) ,
V_12 ? L_3 : L_4 ) ;
return V_12 ;
}
static T_2 F_17 ( const struct V_16 * V_17 ,
T_2 V_41 , bool V_42 )
{
return F_18 ( V_17 -> V_28 , V_17 -> V_31 , V_41 ) ;
}
static int F_19 ( const struct V_32 * V_43 , char * V_1 )
{
memcpy ( V_1 , V_43 -> V_28 , V_43 -> V_31 ) ;
return V_43 -> V_31 ;
}
static int T_3 F_20 ( void )
{
return F_21 ( & V_44 ) ;
}
static void T_4 F_22 ( void )
{
F_23 ( & V_44 ) ;
}
