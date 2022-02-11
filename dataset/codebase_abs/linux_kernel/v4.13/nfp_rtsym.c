static int F_1 ( T_1 V_1 , T_1 V_2 )
{
return ( V_1 & 0x3F ) == V_1 && V_2 < 12 ?
( V_1 << 4 ) | ( V_2 + 4 ) : - 1 ;
}
static void
F_2 ( struct V_3 * V_4 , T_2 V_5 ,
struct V_6 * V_7 , struct V_8 * V_9 )
{
V_7 -> type = V_9 -> type ;
V_7 -> V_10 = V_4 -> V_11 + F_3 ( V_9 -> V_10 ) % V_5 ;
V_7 -> V_12 = ( ( V_13 ) V_9 -> V_14 << 32 ) | F_4 ( V_9 -> V_15 ) ;
V_7 -> V_16 = ( ( V_13 ) V_9 -> V_17 << 32 ) | F_4 ( V_9 -> V_18 ) ;
switch ( V_9 -> V_19 ) {
case V_20 :
V_7 -> V_19 = V_21 ;
break;
case V_22 :
V_7 -> V_19 = V_23 ;
break;
default:
V_7 -> V_19 = V_9 -> V_19 ;
break;
}
if ( V_9 -> V_2 != 0xff )
V_7 -> V_24 = F_1 ( V_9 -> V_25 , V_9 -> V_2 ) ;
else if ( V_9 -> V_25 != 0xff )
V_7 -> V_24 = V_9 -> V_25 ;
else
V_7 -> V_24 = - 1 ;
}
struct V_3 * F_5 ( struct V_26 * V_27 )
{
struct V_3 * V_28 ;
const struct V_29 * V_30 ;
V_30 = F_6 ( V_27 ) ;
V_28 = F_7 ( V_27 , V_30 ) ;
F_8 ( V_30 ) ;
return V_28 ;
}
struct V_3 *
F_7 ( struct V_26 * V_27 , const struct V_29 * V_30 )
{
const T_2 V_31 = F_9 ( V_32 , V_33 , 0 ) |
V_34 ;
T_2 V_35 , V_36 , V_5 , V_37 ;
struct V_8 * V_38 ;
struct V_3 * V_4 ;
int V_39 , V_40 , V_16 ;
if ( ! V_30 )
return NULL ;
F_10 ( V_30 , & V_35 , & V_5 ) ;
F_11 ( V_30 , & V_36 , & V_37 ) ;
if ( ! V_37 || ! V_5 || V_37 % sizeof( * V_38 ) )
return NULL ;
V_37 = F_12 ( V_37 , 8 ) ;
V_5 = F_12 ( V_5 , 8 ) ;
V_38 = F_13 ( V_37 , V_41 ) ;
if ( ! V_38 )
return NULL ;
V_16 = sizeof( * V_4 ) ;
V_16 += V_37 / sizeof( * V_38 ) * sizeof( struct V_6 ) ;
V_16 += V_5 + 1 ;
V_4 = F_13 ( V_16 , V_41 ) ;
if ( ! V_4 )
goto V_42;
V_4 -> V_27 = V_27 ;
V_4 -> V_43 = V_37 / sizeof( * V_38 ) ;
V_4 -> V_11 = ( void * ) & V_4 -> V_44 [ V_4 -> V_43 ] ;
V_39 = F_14 ( V_27 , V_31 , V_36 , V_38 , V_37 ) ;
if ( V_39 != V_37 )
goto V_45;
V_39 = F_14 ( V_27 , V_31 , V_35 , V_4 -> V_11 , V_5 ) ;
if ( V_39 != V_5 )
goto V_45;
V_4 -> V_11 [ V_5 ] = '\0' ;
for ( V_40 = 0 ; V_40 < V_4 -> V_43 ; V_40 ++ )
F_2 ( V_4 , V_5 ,
& V_4 -> V_44 [ V_40 ] , & V_38 [ V_40 ] ) ;
F_15 ( V_38 ) ;
return V_4 ;
V_45:
F_15 ( V_4 ) ;
V_42:
F_15 ( V_38 ) ;
return NULL ;
}
int F_16 ( struct V_3 * V_28 )
{
if ( ! V_28 )
return - V_46 ;
return V_28 -> V_43 ;
}
const struct V_6 * F_17 ( struct V_3 * V_28 , int V_47 )
{
if ( ! V_28 )
return NULL ;
if ( V_47 >= V_28 -> V_43 )
return NULL ;
return & V_28 -> V_44 [ V_47 ] ;
}
const struct V_6 *
F_18 ( struct V_3 * V_28 , const char * V_10 )
{
int V_40 ;
if ( ! V_28 )
return NULL ;
for ( V_40 = 0 ; V_40 < V_28 -> V_43 ; V_40 ++ )
if ( strcmp ( V_10 , V_28 -> V_44 [ V_40 ] . V_10 ) == 0 )
return & V_28 -> V_44 [ V_40 ] ;
return NULL ;
}
V_13 F_19 ( struct V_3 * V_28 , const char * V_10 ,
int * error )
{
const struct V_6 * V_48 ;
T_2 V_49 , V_50 ;
V_13 V_51 ;
int V_39 ;
V_48 = F_18 ( V_28 , V_10 ) ;
if ( ! V_48 ) {
V_39 = - V_52 ;
goto exit;
}
V_50 = F_20 ( V_48 -> V_19 , V_33 , 0 , V_48 -> V_24 ) ;
switch ( V_48 -> V_16 ) {
case 4 :
V_39 = F_21 ( V_28 -> V_27 , V_50 , V_48 -> V_12 , & V_49 ) ;
V_51 = V_49 ;
break;
case 8 :
V_39 = F_22 ( V_28 -> V_27 , V_50 , V_48 -> V_12 , & V_51 ) ;
break;
default:
F_23 ( V_28 -> V_27 ,
L_1 ,
V_10 , V_48 -> V_16 ) ;
V_39 = - V_46 ;
break;
}
if ( V_39 == V_48 -> V_16 )
V_39 = 0 ;
else if ( V_39 >= 0 )
V_39 = - V_53 ;
exit:
if ( error )
* error = V_39 ;
if ( V_39 )
return ~ 0ULL ;
return V_51 ;
}
T_1 T_3 *
F_24 ( struct V_3 * V_28 , const char * V_10 , const char * V_50 ,
unsigned int V_54 , struct V_55 * * V_56 )
{
const struct V_6 * V_48 ;
T_1 T_3 * V_57 ;
V_48 = F_18 ( V_28 , V_10 ) ;
if ( ! V_48 )
return ( T_1 T_3 * ) F_25 ( - V_52 ) ;
if ( V_48 -> V_16 < V_54 ) {
F_23 ( V_28 -> V_27 , L_2 , V_10 ) ;
return ( T_1 T_3 * ) F_25 ( - V_46 ) ;
}
V_57 = F_26 ( V_28 -> V_27 , V_50 , V_48 -> V_24 , V_48 -> V_19 ,
V_48 -> V_12 , V_48 -> V_16 , V_56 ) ;
if ( F_27 ( V_57 ) ) {
F_23 ( V_28 -> V_27 , L_3 ,
V_10 , F_28 ( V_57 ) ) ;
return V_57 ;
}
return V_57 ;
}
