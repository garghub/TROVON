struct V_1 * F_1 ( struct V_1 * V_2 )
{
struct V_1 * V_3 , * V_4 ;
const T_1 * V_5 ;
for ( V_3 = F_2 ( V_2 ) ; V_3 ; ) {
if ( F_3 ( V_3 , L_1 , NULL ) )
break;
V_5 = F_3 ( V_3 , L_2 , NULL ) ;
V_4 = V_3 ;
if ( V_5 == NULL )
V_3 = F_4 ( V_3 ) ;
else
V_3 = F_5 ( * V_5 ) ;
F_6 ( V_4 ) ;
}
return V_3 ;
}
T_2 F_7 ( struct V_1 * V_6 , int V_7 )
{
struct V_1 * V_8 ;
unsigned int V_9 , V_10 ;
const T_1 * V_11 ;
T_3 V_12 , V_13 ;
T_2 V_14 ;
V_8 = F_1 ( V_6 ) ;
if ( V_8 == NULL )
return 0 ;
V_11 = F_3 ( V_8 , L_3 , NULL ) ;
V_9 = V_11 ? * V_11 : 1 ;
V_11 = F_3 ( V_6 , L_4 , & V_10 ) ;
if ( ! V_11 )
return 0 ;
V_10 >>= 2 ;
if ( V_7 >= ( V_10 / ( 2 * V_9 ) ) )
return 0 ;
V_12 = F_8 ( & V_11 [ V_7 * V_9 * 2 ] , V_9 ) ;
V_13 = F_8 ( & V_11 [ V_7 * V_9 * 2 + V_9 ] , V_9 ) ;
V_14 = F_9 ( V_8 , V_12 , V_13 ) ;
F_6 ( V_8 ) ;
return V_14 ;
}
static int F_10 ( void * V_15 , T_3 V_16 )
{
struct V_17 * V_18 = V_15 ;
V_18 -> V_19 = 0 ;
F_11 ( V_18 -> V_20 ) ;
V_18 -> V_20 = F_9 ( V_18 -> V_21 , V_16 , 1 ) ;
if ( F_12 ( V_18 -> V_20 ) )
V_18 -> V_19 = V_16 ;
else
return - V_22 ;
return 0 ;
}
static int F_13 ( void * V_15 , T_3 * V_16 )
{
struct V_17 * V_18 = V_15 ;
* V_16 = V_18 -> V_19 ;
return 0 ;
}
static int F_14 ( void * V_15 , T_3 V_16 )
{
struct V_17 * V_18 = V_15 ;
if ( ! F_12 ( V_18 -> V_20 ) )
return - V_22 ;
F_15 ( V_18 -> V_20 , 0 , V_16 ) ;
return 0 ;
}
static int F_16 ( void * V_15 , T_3 * V_16 )
{
struct V_17 * V_18 = V_15 ;
if ( ! F_12 ( V_18 -> V_20 ) )
return - V_22 ;
* V_16 = F_17 ( V_18 -> V_20 , 0 ) ;
return 0 ;
}
static int F_18 ( struct V_23 * V_24 , struct V_1 * V_21 ,
int V_25 )
{
struct V_17 * V_18 ;
struct V_23 * V_26 ;
V_18 = F_19 ( sizeof( * V_18 ) , V_27 ) ;
if ( ! V_18 )
return - V_28 ;
V_18 -> V_21 = F_2 ( V_21 ) ;
V_18 -> V_20 = V_29 ;
F_20 ( & V_18 -> V_30 ) ;
snprintf ( V_18 -> V_31 , 8 , L_5 , V_25 ) ;
V_18 -> V_32 . V_15 = V_21 -> V_33 ;
V_18 -> V_32 . V_10 = strlen ( V_21 -> V_33 ) ;
V_26 = F_21 ( V_18 -> V_31 , V_24 ) ;
if ( ! V_26 ) {
F_6 ( V_21 ) ;
F_22 ( V_18 ) ;
return - 1 ;
}
F_23 ( L_6 , 0600 , V_26 , V_18 , & V_34 ) ;
F_23 ( L_7 , 0600 , V_26 , V_18 , & V_35 ) ;
F_24 ( L_8 , 0400 , V_26 , & V_18 -> V_32 ) ;
return 0 ;
}
static int F_25 ( void )
{
struct V_1 * V_21 ;
struct V_23 * V_24 ;
int V_25 , V_36 ;
V_24 = F_21 ( L_9 , V_37 ) ;
if ( ! V_24 )
return - 1 ;
V_25 = V_36 = 0 ;
F_26 (dn, L_1 )
V_36 |= F_18 ( V_24 , V_21 , V_25 ++ ) ;
return V_36 ;
}
