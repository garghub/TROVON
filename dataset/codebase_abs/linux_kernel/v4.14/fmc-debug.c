static char * F_1 ( char * V_1 , char * V_2 , int V_3 )
{
int V_4 = V_3 - 1 ;
memcpy ( V_1 , V_2 , V_3 ) ;
V_1 [ V_3 ] = '\0' ;
while ( V_4 >= 0 && V_1 [ V_4 ] == ' ' )
V_1 [ V_4 -- ] = '\0' ;
return V_1 ;
}
static void F_2 ( struct V_5 * V_6 , struct V_7 * V_8 ,
const struct V_9 * V_10 )
{
unsigned long V_11 = V_10 -> V_12 ;
int V_4 , V_13 , V_14 = V_10 -> V_3 , V_15 = V_10 -> V_15 ;
char V_16 [ 64 ] ;
for ( V_4 = 0 ; V_4 < V_14 ; V_4 ++ ) {
union V_17 * V_18 ;
struct V_19 * V_20 ;
struct V_21 * V_22 ;
V_18 = & V_10 -> V_23 [ V_4 ] ;
V_22 = & V_18 -> V_24 . V_21 ;
V_20 = & V_22 -> V_25 ;
for ( V_13 = 0 ; V_13 < V_15 ; V_13 ++ )
F_3 ( V_8 , L_1 ) ;
switch ( V_18 -> V_26 . V_27 ) {
case V_28 :
F_3 ( V_8 , L_2 ,
F_4 ( V_20 -> V_29 ) ,
F_5 ( V_20 -> V_30 ) ,
V_20 -> V_31 ) ;
break;
case V_32 :
F_3 ( V_8 , L_3 ,
F_4 ( V_20 -> V_29 ) ,
F_5 ( V_20 -> V_30 ) ,
V_20 -> V_31 ,
F_4 ( V_22 -> V_33 ) + V_11 ,
F_4 ( V_22 -> V_34 ) + V_11 ) ;
break;
case V_35 :
F_3 ( V_8 , L_4 ,
F_4 ( V_20 -> V_29 ) ,
F_5 ( V_20 -> V_30 ) ,
V_20 -> V_31 ,
F_4 ( V_22 -> V_33 ) + V_11 ) ;
if ( F_6 ( V_10 -> V_36 [ V_4 ] ) ) {
F_3 ( V_8 , L_5 ,
F_7 ( V_10 -> V_36 [ V_4 ] ) ) ;
break;
}
F_2 ( V_6 , V_8 , V_10 -> V_36 [ V_4 ] ) ;
break;
case V_37 :
F_3 ( V_8 , L_6 ) ;
break;
case V_38 :
F_3 ( V_8 , L_7 ,
F_8 ( V_16 , V_18 -> V_39 . V_39 ) ) ;
break;
case V_40 :
F_3 ( V_8 , L_8 ,
F_8 ( V_16 , V_18 -> V_41 . V_42 ) ) ;
F_3 ( V_8 , L_9 ,
F_5 ( V_18 -> V_41 . V_43 ) ,
F_8 ( V_16 , V_18 -> V_41 . V_44 ) ) ;
F_3 ( V_8 , L_10 ,
F_8 ( V_16 , V_18 -> V_41 . V_45 ) ,
F_5 ( V_18 -> V_41 . V_46 ) ) ;
F_3 ( V_8 , L_11 ,
V_18 -> V_41 . V_47 ) ;
break;
case V_48 :
F_3 ( V_8 , L_12 ) ;
break;
default:
F_3 ( V_8 , L_13 ,
V_18 -> V_26 . V_27 ) ;
break;
}
}
}
static int F_9 ( struct V_7 * V_8 , void * V_49 )
{
struct V_5 * V_6 = V_8 -> V_50 ;
if ( ! V_6 -> V_51 ) {
F_3 ( V_8 , L_14 ) ;
return 0 ;
}
F_3 ( V_8 , L_15 , F_10 ( V_6 -> V_52 ) ,
V_6 -> V_53 , V_6 -> V_54 , F_10 ( & V_6 -> V_24 ) ) ;
F_2 ( V_6 , V_8 , V_6 -> V_51 ) ;
return 0 ;
}
static int F_11 ( struct V_55 * V_55 , struct V_56 * V_56 )
{
struct V_5 * V_6 = V_55 -> V_57 ;
return F_12 ( V_56 , F_9 , V_6 ) ;
}
int F_13 ( struct V_5 * V_6 )
{
V_6 -> V_58 = F_14 ( F_10 ( & V_6 -> V_24 ) , NULL ) ;
if ( F_15 ( V_6 -> V_58 ) ) {
F_16 ( L_16 ) ;
return F_7 ( V_6 -> V_58 ) ;
}
V_6 -> V_59 = F_17 ( V_60 , 0444 ,
V_6 -> V_58 , V_6 ,
& V_61 ) ;
if ( F_15 ( V_6 -> V_59 ) )
F_16 ( L_17 ,
V_60 ) ;
return 0 ;
}
void F_18 ( struct V_5 * V_6 )
{
if ( V_6 -> V_58 )
F_19 ( V_6 -> V_58 ) ;
}
