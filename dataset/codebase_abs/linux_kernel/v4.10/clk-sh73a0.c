static struct V_1 * T_1
F_1 ( struct V_2 * V_3 , struct V_4 * V_5 ,
const char * V_6 )
{
const struct V_7 * V_8 = NULL ;
unsigned int V_9 , V_10 , V_11 ;
const char * V_12 ;
unsigned int V_13 = 1 ;
unsigned int div = 1 ;
if ( ! strcmp ( V_6 , L_1 ) ) {
T_2 V_14 = ( F_2 ( V_5 -> V_10 + V_15 ) >> 28 ) & 3 ;
V_12 = F_3 ( V_3 , V_14 >> 1 ) ;
div = ( V_14 & 1 ) + 1 ;
} else if ( ! strncmp ( V_6 , L_2 , 3 ) ) {
void T_3 * V_16 = V_5 -> V_10 ;
T_2 V_17 = V_6 [ 3 ] - '0' ;
V_12 = L_1 ;
switch ( V_17 ) {
case 0 :
V_16 += V_18 ;
break;
case 1 :
V_16 += V_19 ;
break;
case 2 :
V_16 += V_20 ;
break;
case 3 :
V_16 += V_21 ;
break;
default:
return F_4 ( - V_22 ) ;
}
if ( F_2 ( V_5 -> V_10 + V_23 ) & F_5 ( V_17 ) ) {
V_13 = ( ( F_2 ( V_16 ) >> 24 ) & 0x3f ) + 1 ;
if ( V_17 == 1 || V_17 == 2 )
if ( F_2 ( V_16 ) & F_5 ( 20 ) )
V_13 *= 2 ;
}
} else if ( ! strcmp ( V_6 , L_3 ) || ! strcmp ( V_6 , L_4 ) ) {
T_2 V_24 = V_6 [ 3 ] - '0' ;
void T_3 * V_25 = V_5 -> V_10 +
( V_24 ? V_26 : V_27 ) ;
V_12 = V_24 ? L_5 : L_6 ;
V_13 = F_6 ( V_25 ) ;
if ( ! ( V_13 & 0x8000 ) )
V_13 = 1 ;
else
V_13 = ( V_13 & 0x3f ) + 1 ;
} else if ( ! strcmp ( V_6 , L_7 ) ) {
V_12 = L_8 ;
V_8 = V_28 ;
V_10 = V_29 ;
V_9 = 24 ;
V_11 = 5 ;
} else {
struct V_30 * V_31 ;
for ( V_31 = V_32 ; V_31 -> V_6 ; V_31 ++ ) {
if ( ! strcmp ( V_6 , V_31 -> V_6 ) ) {
V_12 = V_31 -> V_33 ;
V_8 = V_34 ;
V_10 = V_31 -> V_10 ;
V_9 = V_31 -> V_9 ;
V_11 = 4 ;
break;
}
}
if ( ! V_31 -> V_6 )
return F_4 ( - V_22 ) ;
}
if ( ! V_8 ) {
return F_7 ( NULL , V_6 , V_12 , 0 ,
V_13 , div ) ;
} else {
return F_8 ( NULL , V_6 , V_12 , 0 ,
V_5 -> V_10 + V_10 , V_9 , V_11 , 0 ,
V_8 , & V_5 -> V_35 ) ;
}
}
static void T_1 F_9 ( struct V_2 * V_3 )
{
struct V_4 * V_5 ;
struct V_1 * * V_36 ;
unsigned int V_37 ;
int V_38 ;
V_38 = F_10 ( V_3 , L_9 ) ;
if ( V_38 < 0 ) {
F_11 ( L_10 , V_39 ) ;
return;
}
V_5 = F_12 ( sizeof( * V_5 ) , V_40 ) ;
V_36 = F_13 ( V_38 , sizeof( * V_36 ) , V_40 ) ;
if ( V_5 == NULL || V_36 == NULL ) {
return;
}
F_14 ( & V_5 -> V_35 ) ;
V_5 -> V_41 . V_36 = V_36 ;
V_5 -> V_41 . V_42 = V_38 ;
V_5 -> V_10 = F_15 ( V_3 , 0 ) ;
if ( F_16 ( V_5 -> V_10 == NULL ) )
return;
F_17 ( 0x108 , V_5 -> V_10 + V_43 ) ;
F_17 ( 0x108 , V_5 -> V_10 + V_44 ) ;
F_17 ( 0x108 , V_5 -> V_10 + V_45 ) ;
for ( V_37 = 0 ; V_37 < V_38 ; ++ V_37 ) {
const char * V_6 ;
struct V_1 * V_1 ;
F_18 ( V_3 , L_9 , V_37 ,
& V_6 ) ;
V_1 = F_1 ( V_3 , V_5 , V_6 ) ;
if ( F_19 ( V_1 ) )
F_11 ( L_11 ,
V_39 , V_3 -> V_6 , V_6 , F_20 ( V_1 ) ) ;
else
V_5 -> V_41 . V_36 [ V_37 ] = V_1 ;
}
F_21 ( V_3 , V_46 , & V_5 -> V_41 ) ;
}
