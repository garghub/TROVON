static int F_1 ( struct V_1 * V_2 , T_1 * V_3 )
{
struct V_4 * V_5 ;
struct V_6 * V_7 ;
V_7 = F_2 ( V_2 , 0xfc6d , 0 , NULL , V_8 ) ;
if ( F_3 ( V_7 ) ) {
F_4 ( L_1 ,
V_2 -> V_9 , F_5 ( V_7 ) ) ;
return F_5 ( V_7 ) ;
}
if ( V_7 -> V_10 != sizeof( * V_5 ) ) {
F_4 ( L_2 , V_2 -> V_9 ) ;
F_6 ( V_7 ) ;
return - V_11 ;
}
V_5 = (struct V_4 * ) V_7 -> V_12 ;
F_7 ( L_3 ,
V_2 -> V_9 , V_5 -> V_13 , V_5 -> V_3 ) ;
* V_3 = V_5 -> V_3 ;
F_6 ( V_7 ) ;
return 0 ;
}
static int F_8 ( struct V_1 * V_2 , T_2 V_14 ,
const struct V_15 * V_16 ,
unsigned char * * V_17 )
{
const T_1 V_18 [] = { 0x51 , 0x04 , 0xfd , 0x77 } ;
struct V_19 * V_20 ;
unsigned char * V_21 ;
int V_22 , V_23 , V_10 ;
T_3 V_24 ;
T_1 V_25 , V_26 , V_12 , V_5 = 0 ;
int V_27 = - 1 ;
const unsigned char * V_28 , * V_29 ;
const unsigned char * V_30 , * V_31 ;
T_4 V_32 = 0 ;
T_2 V_33 , V_34 ;
const T_2 V_35 [] = {
V_36 ,
V_37 ,
V_38 ,
V_39
} ;
V_23 = F_1 ( V_2 , & V_5 ) ;
if ( V_23 )
return V_23 ;
V_24 = sizeof( struct V_19 ) + sizeof( V_18 ) + 3 ;
if ( V_16 -> V_40 < V_24 )
return - V_41 ;
V_28 = V_16 -> V_12 + V_16 -> V_40 - sizeof( V_18 ) ;
if ( memcmp ( V_28 , V_18 , sizeof( V_18 ) ) != 0 ) {
F_4 ( L_4 , V_2 -> V_9 ) ;
return - V_41 ;
}
while ( V_28 >= V_16 -> V_12 + ( sizeof( struct V_19 ) + 3 ) ) {
V_25 = * -- V_28 ;
V_26 = * -- V_28 ;
V_12 = * -- V_28 ;
F_9 ( L_5 , V_25 , V_26 , V_12 ) ;
if ( V_25 == 0xff )
break;
if ( V_26 == 0 ) {
F_4 ( L_6 ,
V_2 -> V_9 ) ;
return - V_41 ;
}
if ( V_25 == 0 && V_26 == 1 ) {
V_27 = V_12 ;
break;
}
V_28 -= V_26 ;
}
if ( V_27 < 0 ) {
F_4 ( L_7 , V_2 -> V_9 ) ;
return - V_41 ;
}
if ( V_27 >= F_10 ( V_35 ) ) {
F_4 ( L_8 , V_2 -> V_9 , V_27 ) ;
return - V_41 ;
}
if ( V_14 != V_35 [ V_27 ] ) {
F_4 ( L_9 , V_2 -> V_9 ,
V_35 [ V_27 ] , V_14 ) ;
return - V_41 ;
}
V_20 = (struct V_19 * ) V_16 -> V_12 ;
if ( memcmp ( V_20 -> V_42 , V_43 , 8 ) != 0 ) {
F_4 ( L_10 , V_2 -> V_9 ) ;
return - V_41 ;
}
V_34 = F_11 ( V_20 -> V_34 ) ;
F_9 ( L_11 ,
F_12 ( V_20 -> V_44 ) , V_34 ) ;
V_24 += 8 * V_34 ;
if ( V_16 -> V_40 < V_24 )
return - V_41 ;
V_29 = V_16 -> V_12 + sizeof( struct V_19 ) ;
V_30 = V_29 + ( sizeof( T_2 ) * V_34 ) ;
V_31 = V_30 + ( sizeof( T_2 ) * V_34 ) ;
for ( V_22 = 0 ; V_22 < V_34 ; V_22 ++ ) {
T_2 V_45 = F_13 ( V_29 +
( V_22 * sizeof( T_2 ) ) ) ;
if ( V_45 == V_5 + 1 ) {
V_33 = F_13 ( V_30 +
( V_22 * sizeof( T_2 ) ) ) ;
V_32 = F_14 ( V_31 +
( V_22 * sizeof( T_4 ) ) ) ;
break;
}
}
if ( ! V_32 ) {
F_4 ( L_12 ,
V_2 -> V_9 , V_5 ) ;
return - V_41 ;
}
F_9 ( L_13 , V_33 , V_32 , V_22 ) ;
V_24 = V_32 + V_33 ;
if ( V_16 -> V_40 < V_24 )
return - V_41 ;
V_10 = V_33 ;
V_21 = F_15 ( V_16 -> V_12 + V_32 , V_33 , V_46 ) ;
if ( ! V_21 )
return - V_47 ;
memcpy ( V_21 + V_33 - 4 , & V_20 -> V_44 , 4 ) ;
* V_17 = V_21 ;
return V_10 ;
}
static int F_16 ( struct V_1 * V_2 ,
const unsigned char * V_12 , int V_48 )
{
struct V_49 * V_50 ;
int V_51 = V_48 / V_52 + 1 ;
int V_53 = V_52 ;
int V_23 = 0 ;
int V_22 ;
V_50 = F_17 ( sizeof( struct V_49 ) , V_46 ) ;
if ( ! V_50 )
return - V_47 ;
for ( V_22 = 0 ; V_22 < V_51 ; V_22 ++ ) {
struct V_6 * V_7 ;
F_9 ( L_14 , V_22 , V_51 ) ;
V_50 -> V_54 = V_22 ;
if ( V_22 == ( V_51 - 1 ) ) {
V_50 -> V_54 |= 0x80 ;
V_53 = V_48 % V_52 ;
}
memcpy ( V_50 -> V_12 , V_12 , V_53 ) ;
V_7 = F_2 ( V_2 , 0xfc20 , V_53 + 1 , V_50 ,
V_8 ) ;
if ( F_3 ( V_7 ) ) {
F_4 ( L_15 ,
V_2 -> V_9 , F_5 ( V_7 ) ) ;
V_23 = - F_5 ( V_7 ) ;
goto V_55;
}
if ( V_7 -> V_10 != sizeof( struct V_56 ) ) {
F_4 ( L_16 ,
V_2 -> V_9 ) ;
F_6 ( V_7 ) ;
V_23 = - V_11 ;
goto V_55;
}
F_6 ( V_7 ) ;
V_12 += V_52 ;
}
V_55:
F_18 ( V_50 ) ;
return V_23 ;
}
static int F_19 ( struct V_1 * V_2 )
{
const struct V_15 * V_16 ;
int V_23 ;
F_7 ( L_17 , V_2 -> V_9 ) ;
V_23 = F_20 ( & V_16 , L_18 , & V_2 -> V_57 ) ;
if ( V_23 < 0 ) {
F_4 ( L_19 , V_2 -> V_9 ) ;
return V_23 ;
}
if ( V_16 -> V_40 < 8 ) {
V_23 = - V_41 ;
goto V_55;
}
if ( ! memcmp ( V_16 -> V_12 , V_43 , 8 ) ) {
F_4 ( L_20 , V_2 -> V_9 ) ;
V_23 = - V_41 ;
goto V_55;
}
V_23 = F_16 ( V_2 , V_16 -> V_12 , V_16 -> V_40 ) ;
V_55:
F_21 ( V_16 ) ;
return V_23 ;
}
static int F_22 ( struct V_1 * V_2 , T_2 V_14 ,
const char * V_58 )
{
unsigned char * V_59 = NULL ;
const struct V_15 * V_16 ;
int V_23 ;
F_7 ( L_21 , V_2 -> V_9 , V_58 ) ;
V_23 = F_20 ( & V_16 , V_58 , & V_2 -> V_57 ) ;
if ( V_23 < 0 ) {
F_4 ( L_22 , V_2 -> V_9 , V_58 ) ;
return V_23 ;
}
V_23 = F_8 ( V_2 , V_14 , V_16 , & V_59 ) ;
if ( V_23 < 0 )
goto V_55;
V_23 = F_16 ( V_2 , V_59 , V_23 ) ;
F_18 ( V_59 ) ;
if ( V_23 < 0 )
goto V_55;
V_55:
F_21 ( V_16 ) ;
return V_23 ;
}
static struct V_6 * F_23 ( struct V_1 * V_2 )
{
struct V_6 * V_7 ;
V_7 = F_2 ( V_2 , V_60 , 0 , NULL ,
V_8 ) ;
if ( F_3 ( V_7 ) ) {
F_4 ( L_23 ,
V_2 -> V_9 , F_5 ( V_7 ) ) ;
return V_7 ;
}
if ( V_7 -> V_10 != sizeof( struct V_61 ) ) {
F_4 ( L_24 ,
V_2 -> V_9 ) ;
F_6 ( V_7 ) ;
return F_24 ( - V_11 ) ;
}
return V_7 ;
}
int F_25 ( struct V_1 * V_2 )
{
struct V_6 * V_7 ;
struct V_61 * V_62 ;
T_2 V_14 ;
V_7 = F_23 ( V_2 ) ;
if ( F_3 ( V_7 ) )
return - F_5 ( V_7 ) ;
V_62 = (struct V_61 * ) V_7 -> V_12 ;
F_7 ( L_25
L_26 , V_2 -> V_9 , V_62 -> V_63 , V_62 -> V_64 ,
V_62 -> V_65 , V_62 -> V_14 ) ;
V_14 = F_11 ( V_62 -> V_14 ) ;
F_6 ( V_7 ) ;
switch ( V_14 ) {
case V_36 :
case V_66 :
return F_19 ( V_2 ) ;
case V_37 :
return F_22 ( V_2 , V_14 ,
L_27 ) ;
case V_38 :
return F_22 ( V_2 , V_14 ,
L_28 ) ;
case V_39 :
return F_22 ( V_2 , V_14 ,
L_29 ) ;
default:
F_7 ( L_30 ) ;
return 0 ;
}
}
