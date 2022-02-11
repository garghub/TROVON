int F_1 ( void )
{
int V_1 ;
V_2 = 2 ;
V_3 = 0 ;
V_4 = F_2 ( V_2 , sizeof( V_4 [ 0 ] ) , V_5 ) ;
if ( V_4 == NULL )
return - V_6 ;
V_1 = F_3 ( V_7 , 0 , 0xffff , 0xffff ,
V_8 , F_4 ( V_8 ) ) ;
if ( V_1 < 0 )
goto V_9;
V_1 = F_3 ( V_10 , 0 , 0xffff , 0xffff ,
V_11 , F_4 ( V_11 ) ) ;
V_9:
return V_1 ;
}
void F_5 ( void )
{
F_6 ( V_4 ) ;
V_4 = NULL ;
V_2 = V_3 = 0 ;
}
static
int F_7 ( void )
{
T_1 V_12 = V_2 * sizeof( V_4 [ 0 ] ) ;
void * V_13 = F_8 ( 2 * V_12 , V_14 ) ;
if ( V_13 == NULL )
return - V_6 ;
memcpy ( V_13 , V_4 , V_12 ) ;
memset ( V_13 + V_12 , 0 , V_12 ) ;
F_6 ( V_4 ) ;
V_4 = V_13 ;
V_2 *= 2 ;
return 0 ;
}
int F_3 ( T_2 type , T_2 V_15 , T_3 V_16 , T_3 V_17 ,
const struct V_18 * V_19 , T_1 V_20 )
{
unsigned long V_21 ;
unsigned V_22 ;
T_3 V_23 ;
int V_1 = 0 ;
F_9 ( & V_24 , V_21 ) ;
if ( V_3 == V_2 ) {
V_1 = F_7 () ;
if ( V_1 < 0 )
goto V_9;
}
V_23 = type << 8 | V_15 ;
for ( V_22 = 0 ; V_22 < V_3 ; V_22 ++ )
if ( V_4 [ V_22 ] . V_23 < type
&& V_4 [ V_22 ] . V_16 < V_16
&& V_4 [ V_22 ] . V_17 < V_17 )
break;
if ( V_22 < V_3 )
memmove ( & V_4 [ V_22 + 1 ] , & V_4 [ V_22 ] , V_3 - V_22 ) ;
V_4 [ V_22 ] . V_23 = type << 8 | V_15 ;
V_4 [ V_22 ] . V_16 = V_16 ;
V_4 [ V_22 ] . V_17 = V_17 ;
V_4 [ V_22 ] . V_19 = V_19 ;
V_4 [ V_22 ] . V_20 = V_20 ;
V_3 ++ ;
V_9:
F_10 ( & V_24 , V_21 ) ;
return V_1 ;
}
int F_11 ( T_2 type , T_2 V_15 , T_3 V_16 , T_3 V_17 ,
const struct V_18 * V_19 , T_1 V_20 )
{
unsigned long V_21 ;
unsigned V_22 ;
struct V_4 V_25 = {
. V_23 = type << 8 | V_15 ,
. V_16 = V_16 ,
. V_17 = V_17 ,
. V_19 = V_19 ,
. V_20 = V_20
} ;
F_9 ( & V_24 , V_21 ) ;
for ( V_22 = 0 ; V_22 < V_3 ; V_22 ++ )
if ( ! memcmp ( & V_4 [ V_22 ] , & V_25 , sizeof( V_25 ) ) )
goto V_26;
F_10 ( & V_24 , V_21 ) ;
return - V_27 ;
V_26:
if ( V_22 < V_3 - 1 )
memmove ( & V_4 [ V_22 ] , & V_4 [ V_22 + 1 ] , V_3 - V_22 - 1 ) ;
V_3 -- ;
F_10 ( & V_24 , V_21 ) ;
return 0 ;
}
static
T_4 F_12 ( struct V_28 * V_28 , struct V_4 * V_29 ,
T_2 V_30 , const struct V_31 * V_32 ,
T_1 V_33 )
{
unsigned V_34 ;
T_4 V_35 ;
struct V_36 * V_37 = & V_28 -> V_38 . V_37 ;
const struct V_18 * V_19 ;
V_35 = - V_27 ;
if ( V_30 >= V_29 -> V_20 ) {
F_13 ( V_37 , L_1 ,
V_29 , V_29 -> V_23 , V_29 -> V_16 , V_29 -> V_17 ,
V_29 -> V_20 , V_30 ) ;
goto V_9;
}
V_35 = - V_27 ;
V_19 = & V_29 -> V_19 [ V_30 ] ;
if ( V_19 -> V_35 == 0 && V_19 -> V_34 == 0 ) {
F_13 ( V_37 , L_2 ,
V_29 , V_29 -> V_23 , V_29 -> V_16 , V_29 -> V_17 ,
V_29 -> V_20 , V_30 ) ;
goto V_9;
}
V_34 = V_19 -> V_34 ;
if ( V_34 == 0 )
V_35 = V_19 -> V_35 ;
else {
const void * V_39 = V_32 ;
T_1 V_40 = 0 ;
V_34 -- ;
V_35 = - V_41 ;
switch ( V_19 -> type ) {
case V_42 : V_40 = sizeof( V_43 ) ; break;
case V_44 : V_40 = sizeof( T_2 ) ; break;
default: F_14 () ;
}
if ( V_34 + V_40 > V_33 ) {
F_13 ( V_37 , L_3
L_4 ,
V_29 , V_29 -> V_23 , V_29 -> V_16 ,
V_29 -> V_17 , V_29 -> V_20 ) ;
goto V_9;
}
V_35 = V_19 -> V_35 ;
V_39 += V_34 ;
switch ( V_19 -> type ) {
case V_42 : V_35 += F_15 ( * ( V_43 * ) V_39 ) ; break;
case V_44 : V_35 += * ( T_2 * ) V_39 ; break;
default: F_14 () ;
}
}
V_9:
return V_35 ;
}
T_4 F_16 ( struct V_28 * V_45 , const struct V_31 * V_32 ,
T_1 V_33 )
{
T_4 V_35 ;
struct V_36 * V_37 = & V_45 -> V_38 . V_37 ;
unsigned long V_21 ;
unsigned V_22 ;
T_3 V_23 , V_46 ;
F_17 ( & V_24 , V_21 ) ;
V_35 = - V_41 ;
if ( V_33 < sizeof( * V_32 ) )
goto V_9;
V_46 = F_15 ( V_32 -> V_47 ) ;
V_23 = V_32 -> V_48 << 8 | ( V_46 & 0xff00 ) >> 8 ;
for ( V_22 = 0 ; V_22 < V_3 ; V_22 ++ ) {
if ( V_4 [ V_22 ] . V_23 != V_23 )
continue;
V_35 = F_12 ( V_45 , & V_4 [ V_22 ] ,
V_46 & 0x00ff , V_32 , V_33 ) ;
if ( V_35 != - V_27 )
goto V_9;
}
F_18 ( V_37 ,
L_5 ,
( unsigned ) V_32 -> V_48 ,
( unsigned ) F_15 ( V_32 -> V_47 ) ,
( unsigned ) V_32 -> V_49 ,
V_32 ) ;
V_35 = - V_27 ;
V_9:
F_19 ( & V_24 , V_21 ) ;
return V_35 ;
}
