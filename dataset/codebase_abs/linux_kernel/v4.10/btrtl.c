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
static const struct {
T_5 V_14 ;
T_6 V_35 ;
} V_36 [] = {
{ V_37 , 0 } ,
{ V_38 , 1 } ,
{ V_39 , 2 } ,
{ V_40 , 3 } ,
{ V_41 , 8 } ,
} ;
V_23 = F_1 ( V_2 , & V_5 ) ;
if ( V_23 )
return V_23 ;
V_24 = sizeof( struct V_19 ) + sizeof( V_18 ) + 3 ;
if ( V_16 -> V_42 < V_24 )
return - V_43 ;
V_28 = V_16 -> V_12 + V_16 -> V_42 - sizeof( V_18 ) ;
if ( memcmp ( V_28 , V_18 , sizeof( V_18 ) ) != 0 ) {
F_4 ( L_4 , V_2 -> V_9 ) ;
return - V_43 ;
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
return - V_43 ;
}
if ( V_25 == 0 && V_26 == 1 ) {
V_27 = V_12 ;
break;
}
V_28 -= V_26 ;
}
if ( V_27 < 0 ) {
F_4 ( L_7 , V_2 -> V_9 ) ;
return - V_43 ;
}
for ( V_22 = 0 ; V_22 < F_10 ( V_36 ) ; V_22 ++ ) {
if ( V_27 == V_36 [ V_22 ] . V_35 )
break;
}
if ( V_22 >= F_10 ( V_36 ) ) {
F_4 ( L_8 , V_2 -> V_9 , V_27 ) ;
return - V_43 ;
}
if ( V_14 != V_36 [ V_22 ] . V_14 ) {
F_4 ( L_9 , V_2 -> V_9 ,
V_36 [ V_22 ] . V_14 , V_14 ) ;
return - V_43 ;
}
V_20 = (struct V_19 * ) V_16 -> V_12 ;
if ( memcmp ( V_20 -> V_44 , V_45 , 8 ) != 0 ) {
F_4 ( L_10 , V_2 -> V_9 ) ;
return - V_43 ;
}
V_34 = F_11 ( V_20 -> V_34 ) ;
F_9 ( L_11 ,
F_12 ( V_20 -> V_46 ) , V_34 ) ;
V_24 += 8 * V_34 ;
if ( V_16 -> V_42 < V_24 )
return - V_43 ;
V_29 = V_16 -> V_12 + sizeof( struct V_19 ) ;
V_30 = V_29 + ( sizeof( T_2 ) * V_34 ) ;
V_31 = V_30 + ( sizeof( T_2 ) * V_34 ) ;
for ( V_22 = 0 ; V_22 < V_34 ; V_22 ++ ) {
T_2 V_47 = F_13 ( V_29 +
( V_22 * sizeof( T_2 ) ) ) ;
if ( V_47 == V_5 + 1 ) {
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
return - V_43 ;
}
F_9 ( L_13 , V_33 , V_32 , V_22 ) ;
V_24 = V_32 + V_33 ;
if ( V_16 -> V_42 < V_24 )
return - V_43 ;
V_10 = V_33 ;
V_21 = F_15 ( V_16 -> V_12 + V_32 , V_33 , V_48 ) ;
if ( ! V_21 )
return - V_49 ;
memcpy ( V_21 + V_33 - 4 , & V_20 -> V_46 , 4 ) ;
* V_17 = V_21 ;
return V_10 ;
}
static int F_16 ( struct V_1 * V_2 ,
const unsigned char * V_12 , int V_50 )
{
struct V_51 * V_52 ;
int V_53 = V_50 / V_54 + 1 ;
int V_55 = V_54 ;
int V_23 = 0 ;
int V_22 ;
V_52 = F_17 ( sizeof( struct V_51 ) , V_48 ) ;
if ( ! V_52 )
return - V_49 ;
for ( V_22 = 0 ; V_22 < V_53 ; V_22 ++ ) {
struct V_6 * V_7 ;
F_9 ( L_14 , V_22 , V_53 ) ;
V_52 -> V_56 = V_22 ;
if ( V_22 == ( V_53 - 1 ) ) {
V_52 -> V_56 |= 0x80 ;
V_55 = V_50 % V_54 ;
}
memcpy ( V_52 -> V_12 , V_12 , V_55 ) ;
V_7 = F_2 ( V_2 , 0xfc20 , V_55 + 1 , V_52 ,
V_8 ) ;
if ( F_3 ( V_7 ) ) {
F_4 ( L_15 ,
V_2 -> V_9 , F_5 ( V_7 ) ) ;
V_23 = - F_5 ( V_7 ) ;
goto V_57;
}
if ( V_7 -> V_10 != sizeof( struct V_58 ) ) {
F_4 ( L_16 ,
V_2 -> V_9 ) ;
F_6 ( V_7 ) ;
V_23 = - V_11 ;
goto V_57;
}
F_6 ( V_7 ) ;
V_12 += V_54 ;
}
V_57:
F_18 ( V_52 ) ;
return V_23 ;
}
static int F_19 ( struct V_1 * V_2 , const char * V_9 , T_1 * * V_59 )
{
const struct V_15 * V_16 ;
int V_23 ;
F_7 ( L_17 , V_2 -> V_9 , V_9 ) ;
V_23 = F_20 ( & V_16 , V_9 , & V_2 -> V_60 ) ;
if ( V_23 < 0 ) {
F_4 ( L_18 , V_2 -> V_9 , V_9 ) ;
return V_23 ;
}
V_23 = V_16 -> V_42 ;
* V_59 = F_15 ( V_16 -> V_12 , V_23 , V_48 ) ;
F_21 ( V_16 ) ;
return V_23 ;
}
static int F_22 ( struct V_1 * V_2 )
{
const struct V_15 * V_16 ;
int V_23 ;
F_7 ( L_19 , V_2 -> V_9 ) ;
V_23 = F_20 ( & V_16 , L_20 , & V_2 -> V_60 ) ;
if ( V_23 < 0 ) {
F_4 ( L_21 , V_2 -> V_9 ) ;
return V_23 ;
}
if ( V_16 -> V_42 < 8 ) {
V_23 = - V_43 ;
goto V_57;
}
if ( ! memcmp ( V_16 -> V_12 , V_45 , 8 ) ) {
F_4 ( L_22 , V_2 -> V_9 ) ;
V_23 = - V_43 ;
goto V_57;
}
V_23 = F_16 ( V_2 , V_16 -> V_12 , V_16 -> V_42 ) ;
V_57:
F_21 ( V_16 ) ;
return V_23 ;
}
static int F_23 ( struct V_1 * V_2 , T_2 V_14 ,
const char * V_61 )
{
unsigned char * V_62 = NULL ;
const struct V_15 * V_16 ;
int V_23 ;
int V_63 ;
T_1 * V_64 = NULL ;
T_1 * V_65 ;
char * V_66 = NULL ;
switch ( V_14 ) {
case V_38 :
V_66 = L_23 ;
break;
case V_39 :
V_66 = L_24 ;
break;
case V_40 :
V_66 = L_25 ;
break;
case V_41 :
V_66 = L_26 ;
break;
default:
F_4 ( L_27 ,
V_2 -> V_9 , V_14 ) ;
break;
}
if ( V_66 ) {
V_63 = F_19 ( V_2 , V_66 , & V_64 ) ;
if ( V_63 < 0 )
V_63 = 0 ;
} else
V_63 = 0 ;
F_7 ( L_17 , V_2 -> V_9 , V_61 ) ;
V_23 = F_20 ( & V_16 , V_61 , & V_2 -> V_60 ) ;
if ( V_23 < 0 ) {
F_4 ( L_18 , V_2 -> V_9 , V_61 ) ;
goto V_67;
}
V_23 = F_8 ( V_2 , V_14 , V_16 , & V_62 ) ;
if ( V_23 < 0 )
goto V_57;
if ( V_63 ) {
V_65 = F_24 ( V_23 + V_63 , V_48 ) ;
if ( ! V_65 ) {
V_23 = - V_49 ;
goto V_57;
}
memcpy ( V_65 , V_62 , V_23 ) ;
F_18 ( V_62 ) ;
memcpy ( V_65 + V_23 , V_64 , V_63 ) ;
V_23 += V_63 ;
V_62 = V_65 ;
}
F_7 ( L_28 , V_63 , V_23 ) ;
V_23 = F_16 ( V_2 , V_62 , V_23 ) ;
V_57:
F_21 ( V_16 ) ;
F_18 ( V_62 ) ;
V_67:
if ( V_63 )
F_18 ( V_64 ) ;
return V_23 ;
}
static struct V_6 * F_25 ( struct V_1 * V_2 )
{
struct V_6 * V_7 ;
V_7 = F_2 ( V_2 , V_68 , 0 , NULL ,
V_8 ) ;
if ( F_3 ( V_7 ) ) {
F_4 ( L_29 ,
V_2 -> V_9 , F_5 ( V_7 ) ) ;
return V_7 ;
}
if ( V_7 -> V_10 != sizeof( struct V_69 ) ) {
F_4 ( L_30 ,
V_2 -> V_9 ) ;
F_6 ( V_7 ) ;
return F_26 ( - V_11 ) ;
}
return V_7 ;
}
int F_27 ( struct V_1 * V_2 )
{
struct V_6 * V_7 ;
struct V_69 * V_70 ;
T_2 V_14 ;
V_7 = F_25 ( V_2 ) ;
if ( F_3 ( V_7 ) )
return - F_5 ( V_7 ) ;
V_70 = (struct V_69 * ) V_7 -> V_12 ;
F_7 ( L_31
L_32 , V_2 -> V_9 , V_70 -> V_71 , V_70 -> V_72 ,
V_70 -> V_73 , V_70 -> V_14 ) ;
V_14 = F_11 ( V_70 -> V_14 ) ;
F_6 ( V_7 ) ;
switch ( V_14 ) {
case V_37 :
case V_74 :
return F_22 ( V_2 ) ;
case V_38 :
return F_23 ( V_2 , V_14 ,
L_33 ) ;
case V_39 :
return F_23 ( V_2 , V_14 ,
L_34 ) ;
case V_40 :
return F_23 ( V_2 , V_14 ,
L_35 ) ;
case V_41 :
return F_23 ( V_2 , V_14 ,
L_36 ) ;
default:
F_7 ( L_37 ) ;
return 0 ;
}
}
