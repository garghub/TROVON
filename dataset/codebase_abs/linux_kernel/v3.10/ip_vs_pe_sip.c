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
struct V_19 * V_21 = F_8 ( V_20 ) ;
struct V_22 V_23 ;
unsigned int V_9 , V_10 , V_11 , V_12 ;
const char * V_8 ;
int V_24 ;
F_9 ( V_18 -> V_25 , V_20 , & V_23 ) ;
if ( V_23 . V_26 != V_27 )
return - V_15 ;
if ( V_21 ) {
V_20 = V_21 ;
V_9 = V_23 . V_28 + sizeof( struct V_29 ) ;
} else
V_9 = V_23 . V_7 + sizeof( struct V_29 ) ;
if ( V_9 >= V_20 -> V_7 )
return - V_15 ;
V_24 = F_10 ( V_20 ) ;
if ( V_24 < 0 )
return V_24 ;
V_8 = V_20 -> V_30 + V_9 ;
V_10 = V_20 -> V_7 - V_9 ;
if ( F_3 ( V_8 , V_9 , V_10 , & V_11 , & V_12 ) )
return - V_15 ;
V_18 -> V_31 = F_11 ( V_8 + V_11 , V_12 , V_32 ) ;
if ( ! V_18 -> V_31 )
return - V_33 ;
V_18 -> V_34 = V_12 ;
return 0 ;
}
static bool F_12 ( const struct V_17 * V_18 ,
struct V_35 * V_36 )
{
bool V_13 = false ;
if ( V_36 -> V_25 == V_18 -> V_25 &&
F_13 ( V_18 -> V_25 , V_18 -> V_37 , & V_36 -> V_37 ) &&
F_13 ( V_18 -> V_26 == V_38 ? V_39 : V_18 -> V_25 ,
V_18 -> V_40 , & V_36 -> V_40 ) &&
V_36 -> V_41 == V_18 -> V_41 &&
V_36 -> V_42 & V_43 &&
V_36 -> V_26 == V_18 -> V_26 &&
V_36 -> V_31 && V_36 -> V_34 == V_18 -> V_34 &&
! memcmp ( V_36 -> V_31 , V_18 -> V_31 , V_18 -> V_34 ) )
V_13 = true ;
F_5 ( 9 , L_2 ,
F_14 ( V_18 -> V_26 ) ,
F_6 ( V_18 -> V_31 , V_18 -> V_34 ) ,
F_15 ( V_18 -> V_25 , V_18 -> V_40 ) , F_16 ( V_18 -> V_41 ) ,
V_13 ? L_3 : L_4 ) ;
return V_13 ;
}
static T_2 F_17 ( const struct V_17 * V_18 ,
T_2 V_44 , bool V_45 )
{
return F_18 ( V_18 -> V_31 , V_18 -> V_34 , V_44 ) ;
}
static int F_19 ( const struct V_35 * V_46 , char * V_1 )
{
memcpy ( V_1 , V_46 -> V_31 , V_46 -> V_34 ) ;
return V_46 -> V_34 ;
}
static int T_3 F_20 ( void )
{
return F_21 ( & V_47 ) ;
}
static void T_4 F_22 ( void )
{
F_23 ( & V_47 ) ;
F_24 () ;
}
