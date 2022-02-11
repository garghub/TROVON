static int T_1 F_1 ( struct V_1 * V_2 , void * V_3 )
{
struct V_4 V_5 = * (struct V_4 * ) V_3 ;
struct V_6 * V_7 = F_2 ( V_2 ) ;
if ( F_3 ( V_7 , V_5 . V_8 ) )
return 0 ;
if ( V_7 -> V_9 . V_10 )
return ! strcmp ( V_7 -> V_9 . V_10 , V_5 . V_11 ) ;
else
return ! strcmp ( L_1 , V_5 . V_11 ) ;
}
static long T_1 F_4 ( struct V_12 * V_13 ,
struct V_1 * V_14 , struct V_1 * * V_15 )
{
struct V_4 V_5 = {} ;
struct V_1 * V_16 ;
if ( V_13 -> V_17 != 12 )
return - V_18 ;
sprintf ( V_5 . V_8 [ 0 ] . V_19 , L_2 ,
'A' + ( ( V_13 -> V_20 . V_8 >> 10 ) & 0x1f ) - 1 ,
'A' + ( ( V_13 -> V_20 . V_8 >> 5 ) & 0x1f ) - 1 ,
'A' + ( ( V_13 -> V_20 . V_8 >> 0 ) & 0x1f ) - 1 ,
V_13 -> V_20 . V_8 >> 16 ) ;
sprintf ( V_5 . V_11 , L_3 , V_13 -> V_20 . V_11 ) ;
* V_15 = F_5 ( & V_21 , NULL , & V_5 ,
F_1 ) ;
if ( ! * V_15 )
return - V_22 ;
V_16 = F_6 ( F_2 ( * V_15 ) ) ;
if ( V_16 ) {
F_7 ( V_16 ) ;
F_8 ( * V_15 ) ;
* V_15 = V_16 ;
}
return 0 ;
}
static int T_1 F_9 ( struct V_1 * V_2 , void * V_3 )
{
unsigned int V_23 = * ( unsigned int * ) V_3 ;
return F_10 ( V_2 ) && F_11 ( V_2 ) -> V_23 == V_23 ;
}
static long T_1 F_12 ( struct V_12 * V_13 ,
struct V_1 * V_14 , struct V_1 * * V_15 )
{
unsigned int V_23 ;
if ( V_13 -> V_17 != 6 )
return - V_18 ;
if ( ! V_14 )
return - V_18 ;
V_23 = F_13 ( V_13 -> V_24 . V_2 , V_13 -> V_24 . V_25 ) ;
* V_15 = F_14 ( V_14 , & V_23 , F_9 ) ;
if ( ! * V_15 )
return - V_22 ;
return 0 ;
}
static long T_1 F_15 ( struct V_12 * V_13 ,
struct V_1 * V_14 , struct V_1 * * V_15 )
{
if ( V_13 -> V_17 != 4 )
return - V_18 ;
if ( V_13 -> V_26 != V_27 &&
V_13 -> V_26 != V_28 )
return - V_18 ;
if ( ! V_14 )
return - V_22 ;
* V_15 = F_7 ( V_14 ) ;
return V_13 -> V_26 ;
}
struct V_1 * T_1 F_16 ( struct V_12 * * V_13 ,
T_2 * V_29 )
{
struct V_1 * V_14 = NULL , * V_15 ;
long V_30 = 0 ;
if ( ! * V_29 )
return NULL ;
while ( ! V_30 ) {
if ( * V_29 < 4 || * V_29 < ( * V_13 ) -> V_17 )
V_30 = - V_18 ;
else if ( ( * V_13 ) -> type == V_31 &&
( * V_13 ) -> V_26 == V_32 )
V_30 = F_4 ( * V_13 , V_14 , & V_15 ) ;
else if ( ( * V_13 ) -> type == V_33 &&
( * V_13 ) -> V_26 == V_34 )
V_30 = F_12 ( * V_13 , V_14 , & V_15 ) ;
else if ( ( ( * V_13 ) -> type == V_35 ||
( * V_13 ) -> type == V_36 ) )
V_30 = F_15 ( * V_13 , V_14 , & V_15 ) ;
else
V_30 = - V_37 ;
F_8 ( V_14 ) ;
if ( V_30 < 0 )
return F_17 ( V_30 ) ;
V_14 = V_15 ;
* V_13 = ( void * ) * V_13 + ( * V_13 ) -> V_17 ;
* V_29 -= ( * V_13 ) -> V_17 ;
}
if ( V_30 == V_28 )
* V_29 = 0 ;
return V_15 ;
}
