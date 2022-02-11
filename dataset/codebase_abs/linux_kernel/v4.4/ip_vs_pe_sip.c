static const char * F_1 ( char * V_1 , T_1 V_2 ,
const char * V_3 , T_1 V_4 ,
int * V_5 )
{
T_1 V_6 = 64 ;
T_1 V_7 = F_2 ( V_6 , V_4 , V_2 - * V_5 - 1 ) ;
memcpy ( V_1 + * V_5 , V_3 , V_7 ) ;
V_1 [ * V_5 + V_7 ] = '\0' ;
* V_5 += V_7 + 1 ;
return V_1 + * V_5 - V_7 ;
}
static int F_3 ( const char * V_8 , unsigned int V_9 ,
unsigned int V_10 ,
unsigned int * V_11 , unsigned int * V_12 )
{
while ( 1 ) {
int V_13 = F_4 ( NULL , V_8 , V_9 , V_10 ,
V_14 , V_11 ,
V_12 ) ;
if ( V_13 > 0 )
break;
if ( ! V_13 )
return - V_15 ;
V_9 += * V_11 ;
}
if ( * V_12 > V_16 )
return - V_15 ;
if ( * V_11 + * V_12 == V_10 )
return - V_15 ;
if ( * ( V_8 + * V_11 + * V_12 ) != '\r' &&
* ( V_8 + * V_11 + * V_12 ) != '\n' )
return - V_15 ;
F_5 ( 9 , L_1 ,
F_6 ( V_8 + * V_11 , * V_12 ) ,
* V_12 ) ;
return 0 ;
}
static int
F_7 ( struct V_17 * V_18 , struct V_19 * V_20 )
{
struct V_21 V_22 ;
unsigned int V_9 , V_10 , V_11 , V_12 ;
const char * V_8 ;
int V_23 ;
F_8 ( V_18 -> V_24 , V_20 , false , & V_22 ) ;
if ( V_22 . V_25 != V_26 )
return - V_15 ;
V_9 = V_22 . V_7 + sizeof( struct V_27 ) ;
if ( V_9 >= V_20 -> V_7 )
return - V_15 ;
V_23 = F_9 ( V_20 ) ;
if ( V_23 < 0 )
return V_23 ;
V_8 = V_20 -> V_28 + V_9 ;
V_10 = V_20 -> V_7 - V_9 ;
if ( F_3 ( V_8 , V_9 , V_10 , & V_11 , & V_12 ) )
return - V_15 ;
V_18 -> V_29 = F_10 ( V_8 + V_11 , V_12 , V_30 ) ;
if ( ! V_18 -> V_29 )
return - V_31 ;
V_18 -> V_32 = V_12 ;
return 0 ;
}
static bool F_11 ( const struct V_17 * V_18 ,
struct V_33 * V_34 )
{
bool V_13 = false ;
if ( V_34 -> V_24 == V_18 -> V_24 &&
F_12 ( V_18 -> V_24 , V_18 -> V_35 , & V_34 -> V_35 ) &&
F_12 ( V_18 -> V_25 == V_36 ? V_37 : V_18 -> V_24 ,
V_18 -> V_38 , & V_34 -> V_38 ) &&
V_34 -> V_39 == V_18 -> V_39 &&
V_34 -> V_40 & V_41 &&
V_34 -> V_25 == V_18 -> V_25 &&
V_34 -> V_29 && V_34 -> V_32 == V_18 -> V_32 &&
! memcmp ( V_34 -> V_29 , V_18 -> V_29 , V_18 -> V_32 ) )
V_13 = true ;
F_5 ( 9 , L_2 ,
F_13 ( V_18 -> V_25 ) ,
F_6 ( V_18 -> V_29 , V_18 -> V_32 ) ,
F_14 ( V_18 -> V_24 , V_18 -> V_38 ) , F_15 ( V_18 -> V_39 ) ,
V_13 ? L_3 : L_4 ) ;
return V_13 ;
}
static T_2 F_16 ( const struct V_17 * V_18 ,
T_2 V_42 , bool V_43 )
{
return F_17 ( V_18 -> V_29 , V_18 -> V_32 , V_42 ) ;
}
static int F_18 ( const struct V_33 * V_44 , char * V_1 )
{
memcpy ( V_1 , V_44 -> V_29 , V_44 -> V_32 ) ;
return V_44 -> V_32 ;
}
static int T_3 F_19 ( void )
{
return F_20 ( & V_45 ) ;
}
static void T_4 F_21 ( void )
{
F_22 ( & V_45 ) ;
F_23 () ;
}
