static T_1
F_1 ( int V_1 , void * V_2 )
{
struct V_3 * V_4 = V_2 ;
unsigned long V_5 ;
int V_6 ;
F_2 ( & V_4 -> V_7 , V_5 ) ;
V_6 = F_3 ( V_4 -> V_8 , V_4 -> V_9 ) ;
if ( ( V_6 > 0 ) && ( V_6 & V_10 ) ) {
F_4 ( & V_11 ) ;
}
F_5 ( & V_4 -> V_7 , V_5 ) ;
return V_12 ;
}
static int
F_6 ( char * V_13 , int * V_14 , int * V_15 , int * V_16 , char * V_17 )
{
char * V_18 ;
* V_14 = F_7 ( V_13 ) ;
V_13 += 4 ;
* V_15 = F_7 ( V_13 ) ;
V_13 += 4 ;
if ( * V_13 ++ != 2 ) {
return - 1 ;
}
if ( * V_13 ++ != V_19 ) {
return - 1 ;
}
* V_16 = F_7 ( V_13 ) ;
V_13 += 4 ;
if ( * V_13 ++ != V_20 ) {
return - 1 ;
}
V_13 [ V_21 - 1 ] = '\0' ;
V_13 += 2 ;
V_18 = V_17 + sprintf ( V_17 , L_1 , V_13 ) ;
for ( V_18 -- ;
( V_18 != V_17 ) && ( ( * V_18 == 0xd ) || ( * V_18 == 0xa ) ) ;
V_18 -- ) {
* V_18 = '\0' ;
}
return 0 ;
}
static char *
F_8 ( int V_15 )
{
int V_22 = ( V_15 & V_23 ) ;
int V_24 = ( V_15 & V_25 ) ;
char * V_26 = V_27 ;
switch ( V_22 ) {
case V_28 :
switch ( V_24 ) {
case V_29 :
case V_30 :
V_26 = V_31 ;
break;
case V_32 :
case V_33 :
V_26 = V_34 ;
break;
}
break;
case V_35 :
switch ( V_24 ) {
case V_36 :
V_26 = V_31 ;
break;
case V_37 :
V_26 = V_38 ;
break;
}
break;
case V_39 :
switch ( V_24 ) {
case V_40 :
V_26 = V_31 ;
break;
case V_41 :
V_26 = V_38 ;
break;
case V_42 :
V_26 = V_34 ;
break;
}
break;
case V_43 :
V_26 = V_34 ;
break;
case V_44 :
V_26 = V_34 ;
break;
case V_45 :
V_26 = V_31 ;
break;
case V_46 :
V_26 = V_34 ;
break;
}
return V_26 ;
}
static void
F_9 ( char * V_13 , int V_47 )
{
static int V_48 = 0 ;
int V_15 , V_16 , V_14 , V_49 ;
char V_17 [ V_21 ] ;
char * V_50 ;
if ( F_6 ( V_13 , & V_14 , & V_15 , & V_16 , V_17 ) < 0 ) {
return;
}
V_50 = F_8 ( V_15 ) ;
V_49 = ( V_15 & V_23 ) ;
if ( V_49 == V_46 || V_15 == V_51 ) {
if ( V_48 )
return;
V_48 = 1 ;
if ( V_49 == V_46 )
F_10 ( V_27 L_2
L_3 ) ;
else if ( V_15 == V_51 )
F_10 ( V_38 L_4
L_5
L_3 ) ;
F_11 ( V_52 , 0 ) ;
} else {
F_10 ( L_6 , V_50 , V_16 , V_17 ) ;
}
}
void
F_12 ( unsigned long V_53 )
{
int V_6 ;
int V_47 ;
unsigned long V_5 ;
struct V_3 * V_4 = V_54 ;
V_47 = V_21 ;
F_2 ( & V_4 -> V_7 , V_5 ) ;
V_6 = F_13 ( V_4 -> V_8 , V_4 -> V_9 ,
V_4 -> V_55 , & V_47 ) ;
while ( ! ( V_6 < 0 ) ) {
F_5 ( & V_4 -> V_7 , V_5 ) ;
F_9 ( V_4 -> V_55 , V_47 ) ;
V_47 = V_21 ;
F_2 ( & V_4 -> V_7 , V_5 ) ;
V_6 = F_13 ( V_4 -> V_8 , V_4 -> V_9 ,
V_4 -> V_55 , & V_47 ) ;
}
F_5 ( & V_4 -> V_7 , V_5 ) ;
}
void
F_14 ( struct V_56 * V_57 )
{
int V_58 ;
V_54 = F_15 ( sizeof ( struct V_3 ) , V_59 ) ;
if ( V_54 == NULL ) {
F_10 ( V_31 L_7
L_8 , V_60 ) ;
return;
}
V_54 -> V_8 = V_57 -> V_61 ;
F_16 ( & V_54 -> V_7 ) ;
V_54 -> V_9 = F_17 ( V_57 -> V_61 ) ;
if ( V_54 -> V_9 < 0 ) {
F_18 ( V_54 ) ;
F_10 ( V_31 L_9 ,
V_60 ) ;
return;
}
V_58 = F_19 ( V_62 , F_1 ,
V_63 , L_10 , V_54 ) ;
if ( V_58 ) {
F_10 ( V_31 L_11 ,
V_60 , V_58 ) ;
F_20 ( V_54 -> V_8 , V_54 -> V_9 ) ;
F_18 ( V_54 ) ;
return;
}
}
