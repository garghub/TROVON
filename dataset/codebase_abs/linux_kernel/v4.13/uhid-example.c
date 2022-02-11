static int F_1 ( int V_1 , const struct V_2 * V_3 )
{
T_1 V_4 ;
V_4 = F_2 ( V_1 , V_3 , sizeof( * V_3 ) ) ;
if ( V_4 < 0 ) {
fprintf ( V_5 , L_1 ) ;
return - V_6 ;
} else if ( V_4 != sizeof( * V_3 ) ) {
fprintf ( V_5 , L_2 ,
V_4 , sizeof( V_3 ) ) ;
return - V_7 ;
} else {
return 0 ;
}
}
static int F_3 ( int V_1 )
{
struct V_2 V_3 ;
memset ( & V_3 , 0 , sizeof( V_3 ) ) ;
V_3 . type = V_8 ;
strcpy ( ( char * ) V_3 . V_9 . F_3 . V_10 , L_3 ) ;
V_3 . V_9 . F_3 . V_11 = V_12 ;
V_3 . V_9 . F_3 . V_13 = sizeof( V_12 ) ;
V_3 . V_9 . F_3 . V_14 = V_15 ;
V_3 . V_9 . F_3 . V_16 = 0x15d9 ;
V_3 . V_9 . F_3 . V_17 = 0x0a37 ;
V_3 . V_9 . F_3 . V_18 = 0 ;
V_3 . V_9 . F_3 . V_19 = 0 ;
return F_1 ( V_1 , & V_3 ) ;
}
static void F_4 ( int V_1 )
{
struct V_2 V_3 ;
memset ( & V_3 , 0 , sizeof( V_3 ) ) ;
V_3 . type = V_20 ;
F_1 ( V_1 , & V_3 ) ;
}
static void F_5 ( struct V_2 * V_3 )
{
if ( V_3 -> V_9 . V_21 . V_22 != V_23 )
return;
if ( V_3 -> V_9 . V_21 . V_24 != 2 )
return;
if ( V_3 -> V_9 . V_21 . V_25 [ 0 ] != 0x2 )
return;
fprintf ( V_5 , L_4 ,
V_3 -> V_9 . V_21 . V_25 [ 1 ] ) ;
}
static int F_6 ( int V_1 )
{
struct V_2 V_3 ;
T_1 V_4 ;
memset ( & V_3 , 0 , sizeof( V_3 ) ) ;
V_4 = F_7 ( V_1 , & V_3 , sizeof( V_3 ) ) ;
if ( V_4 == 0 ) {
fprintf ( V_5 , L_5 ) ;
return - V_7 ;
} else if ( V_4 < 0 ) {
fprintf ( V_5 , L_6 ) ;
return - V_6 ;
} else if ( V_4 != sizeof( V_3 ) ) {
fprintf ( V_5 , L_7 ,
V_4 , sizeof( V_3 ) ) ;
return - V_7 ;
}
switch ( V_3 . type ) {
case V_26 :
fprintf ( V_5 , L_8 ) ;
break;
case V_27 :
fprintf ( V_5 , L_9 ) ;
break;
case V_28 :
fprintf ( V_5 , L_10 ) ;
break;
case V_29 :
fprintf ( V_5 , L_11 ) ;
break;
case V_30 :
fprintf ( V_5 , L_12 ) ;
F_5 ( & V_3 ) ;
break;
case V_31 :
fprintf ( V_5 , L_13 ) ;
break;
default:
fprintf ( V_5 , L_14 , V_3 . type ) ;
}
return 0 ;
}
static int F_8 ( int V_1 )
{
struct V_2 V_3 ;
memset ( & V_3 , 0 , sizeof( V_3 ) ) ;
V_3 . type = V_32 ;
V_3 . V_9 . V_33 . V_24 = 5 ;
V_3 . V_9 . V_33 . V_25 [ 0 ] = 0x1 ;
if ( V_34 )
V_3 . V_9 . V_33 . V_25 [ 1 ] |= 0x1 ;
if ( V_35 )
V_3 . V_9 . V_33 . V_25 [ 1 ] |= 0x2 ;
if ( V_36 )
V_3 . V_9 . V_33 . V_25 [ 1 ] |= 0x4 ;
V_3 . V_9 . V_33 . V_25 [ 2 ] = V_37 ;
V_3 . V_9 . V_33 . V_25 [ 3 ] = V_38 ;
V_3 . V_9 . V_33 . V_25 [ 4 ] = V_39 ;
return F_1 ( V_1 , & V_3 ) ;
}
static int F_9 ( int V_1 )
{
char V_40 [ 128 ] ;
T_1 V_4 , V_41 ;
V_4 = F_7 ( V_42 , V_40 , sizeof( V_40 ) ) ;
if ( V_4 == 0 ) {
fprintf ( V_5 , L_15 ) ;
return - V_7 ;
} else if ( V_4 < 0 ) {
fprintf ( V_5 , L_16 ) ;
return - V_6 ;
}
for ( V_41 = 0 ; V_41 < V_4 ; ++ V_41 ) {
switch ( V_40 [ V_41 ] ) {
case '1' :
V_34 = ! V_34 ;
V_4 = F_8 ( V_1 ) ;
if ( V_4 )
return V_4 ;
break;
case '2' :
V_35 = ! V_35 ;
V_4 = F_8 ( V_1 ) ;
if ( V_4 )
return V_4 ;
break;
case '3' :
V_36 = ! V_36 ;
V_4 = F_8 ( V_1 ) ;
if ( V_4 )
return V_4 ;
break;
case 'a' :
V_37 = - 20 ;
V_4 = F_8 ( V_1 ) ;
V_37 = 0 ;
if ( V_4 )
return V_4 ;
break;
case 'd' :
V_37 = 20 ;
V_4 = F_8 ( V_1 ) ;
V_37 = 0 ;
if ( V_4 )
return V_4 ;
break;
case 'w' :
V_38 = - 20 ;
V_4 = F_8 ( V_1 ) ;
V_38 = 0 ;
if ( V_4 )
return V_4 ;
break;
case 's' :
V_38 = 20 ;
V_4 = F_8 ( V_1 ) ;
V_38 = 0 ;
if ( V_4 )
return V_4 ;
break;
case 'r' :
V_39 = 1 ;
V_4 = F_8 ( V_1 ) ;
V_39 = 0 ;
if ( V_4 )
return V_4 ;
break;
case 'f' :
V_39 = - 1 ;
V_4 = F_8 ( V_1 ) ;
V_39 = 0 ;
if ( V_4 )
return V_4 ;
break;
case 'q' :
return - V_43 ;
default:
fprintf ( V_5 , L_17 , V_40 [ V_41 ] ) ;
}
}
return 0 ;
}
int main ( int V_44 , char * * V_45 )
{
int V_1 ;
const char * V_46 = L_18 ;
struct V_47 V_48 [ 2 ] ;
int V_4 ;
struct V_49 V_50 ;
V_4 = F_10 ( V_42 , & V_50 ) ;
if ( V_4 ) {
fprintf ( V_5 , L_19 ) ;
} else {
V_50 . V_51 &= ~ V_52 ;
V_50 . V_53 [ V_54 ] = 1 ;
V_4 = F_11 ( V_42 , V_55 , & V_50 ) ;
if ( V_4 )
fprintf ( V_5 , L_20 ) ;
}
if ( V_44 >= 2 ) {
if ( ! strcmp ( V_45 [ 1 ] , L_21 ) || ! strcmp ( V_45 [ 1 ] , L_22 ) ) {
fprintf ( V_5 , L_23 , V_45 [ 0 ] , V_46 ) ;
return V_56 ;
} else {
V_46 = V_45 [ 1 ] ;
}
}
fprintf ( V_5 , L_24 , V_46 ) ;
V_1 = F_12 ( V_46 , V_57 | V_58 ) ;
if ( V_1 < 0 ) {
fprintf ( V_5 , L_25 , V_46 ) ;
return V_59 ;
}
fprintf ( V_5 , L_26 ) ;
V_4 = F_3 ( V_1 ) ;
if ( V_4 ) {
F_13 ( V_1 ) ;
return V_59 ;
}
V_48 [ 0 ] . V_1 = V_42 ;
V_48 [ 0 ] . V_60 = V_61 ;
V_48 [ 1 ] . V_1 = V_1 ;
V_48 [ 1 ] . V_60 = V_61 ;
fprintf ( V_5 , L_27 ) ;
while ( 1 ) {
V_4 = F_14 ( V_48 , 2 , - 1 ) ;
if ( V_4 < 0 ) {
fprintf ( V_5 , L_28 ) ;
break;
}
if ( V_48 [ 0 ] . V_62 & V_63 ) {
fprintf ( V_5 , L_29 ) ;
break;
}
if ( V_48 [ 1 ] . V_62 & V_63 ) {
fprintf ( V_5 , L_30 ) ;
break;
}
if ( V_48 [ 0 ] . V_62 & V_61 ) {
V_4 = F_9 ( V_1 ) ;
if ( V_4 )
break;
}
if ( V_48 [ 1 ] . V_62 & V_61 ) {
V_4 = F_6 ( V_1 ) ;
if ( V_4 )
break;
}
}
fprintf ( V_5 , L_31 ) ;
F_4 ( V_1 ) ;
return V_56 ;
}
