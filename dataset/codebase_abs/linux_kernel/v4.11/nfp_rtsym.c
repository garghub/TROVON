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
static int F_5 ( struct V_26 * V_27 )
{
const T_2 V_28 = F_6 ( V_29 , V_30 , 0 ) |
V_31 ;
T_2 V_32 , V_33 , V_5 , V_34 ;
struct V_8 * V_35 ;
struct V_3 * V_4 ;
const struct V_36 * V_37 ;
int V_38 , V_39 , V_16 ;
V_37 = F_7 ( V_27 ) ;
if ( ! V_37 )
return - V_40 ;
F_8 ( V_37 , & V_32 , & V_5 ) ;
F_9 ( V_37 , & V_33 , & V_34 ) ;
F_10 ( V_37 ) ;
if ( ! V_34 || ! V_5 || V_34 % sizeof( * V_35 ) )
return - V_41 ;
V_34 = F_11 ( V_34 , 8 ) ;
V_5 = F_11 ( V_5 , 8 ) ;
V_35 = F_12 ( V_34 , V_42 ) ;
if ( ! V_35 )
return - V_43 ;
V_16 = sizeof( * V_4 ) ;
V_16 += V_34 / sizeof( * V_35 ) * sizeof( struct V_6 ) ;
V_16 += V_5 + 1 ;
V_4 = F_12 ( V_16 , V_42 ) ;
if ( ! V_4 ) {
V_38 = - V_43 ;
goto V_44;
}
V_4 -> V_45 = V_34 / sizeof( * V_35 ) ;
V_4 -> V_11 = ( void * ) & V_4 -> V_46 [ V_4 -> V_45 ] ;
V_38 = F_13 ( V_27 , V_28 , V_33 , V_35 , V_34 ) ;
if ( V_38 != V_34 )
goto V_47;
V_38 = F_13 ( V_27 , V_28 , V_32 , V_4 -> V_11 , V_5 ) ;
if ( V_38 != V_5 )
goto V_47;
V_4 -> V_11 [ V_5 ] = '\0' ;
for ( V_39 = 0 ; V_39 < V_4 -> V_45 ; V_39 ++ )
F_2 ( V_4 , V_5 ,
& V_4 -> V_46 [ V_39 ] , & V_35 [ V_39 ] ) ;
F_14 ( V_35 ) ;
F_15 ( V_27 , V_4 ) ;
return 0 ;
V_47:
F_14 ( V_4 ) ;
V_44:
F_14 ( V_35 ) ;
return V_38 ;
}
static struct V_3 * V_6 ( struct V_26 * V_27 )
{
struct V_3 * V_4 ;
int V_38 ;
V_4 = V_3 ( V_27 ) ;
if ( V_4 )
return V_4 ;
V_38 = F_5 ( V_27 ) ;
if ( V_38 < 0 )
return F_16 ( V_38 ) ;
return V_3 ( V_27 ) ;
}
int F_17 ( struct V_26 * V_27 )
{
struct V_3 * V_4 ;
V_4 = V_6 ( V_27 ) ;
if ( F_18 ( V_4 ) )
return F_19 ( V_4 ) ;
return V_4 -> V_45 ;
}
const struct V_6 * F_20 ( struct V_26 * V_27 , int V_48 )
{
struct V_3 * V_4 ;
V_4 = V_6 ( V_27 ) ;
if ( F_18 ( V_4 ) )
return NULL ;
if ( V_48 >= V_4 -> V_45 )
return NULL ;
return & V_4 -> V_46 [ V_48 ] ;
}
const struct V_6 * F_21 ( struct V_26 * V_27 , const char * V_10 )
{
struct V_3 * V_4 ;
int V_39 ;
V_4 = V_6 ( V_27 ) ;
if ( F_18 ( V_4 ) )
return NULL ;
for ( V_39 = 0 ; V_39 < V_4 -> V_45 ; V_39 ++ ) {
if ( strcmp ( V_10 , V_4 -> V_46 [ V_39 ] . V_10 ) == 0 )
return & V_4 -> V_46 [ V_39 ] ;
}
return NULL ;
}
V_13 F_22 ( struct V_26 * V_27 , const char * V_10 , int * error )
{
const struct V_6 * V_49 ;
T_2 V_50 , V_51 ;
V_13 V_52 ;
int V_38 ;
V_49 = F_21 ( V_27 , V_10 ) ;
if ( ! V_49 ) {
V_38 = - V_53 ;
goto exit;
}
V_51 = F_23 ( V_49 -> V_19 , V_30 , 0 , V_49 -> V_24 ) ;
switch ( V_49 -> V_16 ) {
case 4 :
V_38 = F_24 ( V_27 , V_51 , V_49 -> V_12 , & V_50 ) ;
V_52 = V_50 ;
break;
case 8 :
V_38 = F_25 ( V_27 , V_51 , V_49 -> V_12 , & V_52 ) ;
break;
default:
F_26 ( V_27 ,
L_1 ,
V_10 , V_49 -> V_16 ) ;
V_38 = - V_54 ;
break;
}
if ( V_38 == V_49 -> V_16 )
V_38 = 0 ;
else if ( V_38 >= 0 )
V_38 = - V_40 ;
exit:
if ( error )
* error = V_38 ;
if ( V_38 )
return ~ 0ULL ;
return V_52 ;
}
