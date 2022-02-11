void F_1 (
struct V_1 * V_2 , enum V_3 V_4
)
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
switch ( V_4 ) {
case V_7 :
V_6 -> V_8 [ 0 ] = ( ( V_6 -> V_8 [ 0 ] & 0xfffff3ff ) | V_9 | V_10 ) ;
F_3 ( V_2 , V_11 , V_12 , V_13 , V_6 -> V_8 [ 0 ] ) ;
F_3 ( V_2 , V_14 , V_12 , V_13 , V_6 -> V_8 [ 0 ] ) ;
break;
case V_15 :
V_6 -> V_8 [ 0 ] = ( ( V_6 -> V_8 [ 0 ] & 0xfffff3ff ) | V_9 ) ;
F_3 ( V_2 , V_11 , V_12 , V_13 , V_6 -> V_8 [ 0 ] ) ;
F_3 ( V_2 , V_14 , V_12 , V_13 , V_6 -> V_8 [ 0 ] ) ;
break;
default:
break;
}
}
static int F_4 ( struct V_1 * V_2 )
{
T_1 V_16 = 0 ;
T_2 V_17 ;
struct V_18 * V_19 ;
int V_20 = V_21 ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
static char V_22 [] = V_23 ;
static char V_24 [] = V_25 ;
static T_3 V_26 [] = V_27 ;
char * V_28 , * V_29 , * V_30 ;
V_28 = V_22 ;
V_29 = V_24 ;
V_30 = V_26 ;
for ( V_17 = 0 ; V_17 < V_6 -> V_31 ; V_17 ++ ) {
V_19 = & V_6 -> V_32 [ V_17 ] ;
switch ( V_17 ) {
case V_33 :
case V_34 :
V_16 = F_5 ( V_2 , V_19 -> V_35 , V_36 ) ;
break;
case V_37 :
case V_38 :
V_16 = F_5 ( V_2 , V_19 -> V_35 , V_36 << 16 ) ;
break;
}
F_6 ( V_2 , V_19 -> V_39 , V_36 << 16 , 0x1 ) ;
F_7 ( 1 ) ;
F_6 ( V_2 , V_19 -> V_40 , V_36 , 0x1 ) ;
F_7 ( 1 ) ;
F_6 ( V_2 , V_19 -> V_41 , V_42 , 0x0 ) ;
F_7 ( 1 ) ;
F_6 ( V_2 , V_19 -> V_41 , V_43 , 0x0 ) ;
F_7 ( 1 ) ;
switch ( V_17 ) {
case V_33 :
if ( F_8 ( V_2 , V_28 ,
V_17 ) == V_44 ) {
if ( V_45 == F_9 ( & V_6 -> V_46 , V_47 , ( V_48 ) V_17 ) )
V_20 = V_44 ;
}
break;
case V_37 :
if ( F_8 ( V_2 , V_29 ,
V_17 ) == V_44 ) {
if ( V_45 == F_9 ( & V_6 -> V_46 , V_47 , ( V_48 ) V_17 ) )
V_20 = V_44 ;
}
break;
case V_34 :
break;
case V_38 :
break;
}
;
switch ( V_17 ) {
case V_33 :
case V_34 :
F_6 ( V_2 , V_19 -> V_35 , V_36 , V_16 ) ;
break;
case V_37 :
case V_38 :
F_6 ( V_2 , V_19 -> V_35 , V_36 << 16 , V_16 ) ;
break;
}
if ( V_20 != V_21 ) {
goto V_49;
}
}
if ( F_10 ( V_2 , V_30 ) ==
V_44 ) {
F_11 ( & V_6 -> V_46 ) ;
}
return V_20 ;
V_49:
return V_20 ;
}
int F_12 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_20 = V_21 ;
if ( V_6 -> V_50 == V_51 )
V_6 -> V_31 = 1 ;
else
V_6 -> V_31 = 2 ;
V_20 = F_4 ( V_2 ) ;
return V_20 ;
}
