static const char * F_1 ( unsigned int V_1 )
{
switch ( V_1 ) {
case V_2 :
return L_1 ;
case V_3 :
return L_2 ;
case V_4 :
return L_3 ;
case V_5 :
return L_4 ;
case V_6 :
return L_5 ;
case V_7 :
return L_6 ;
case V_8 :
return L_7 ;
case V_9 :
return L_8 ;
case V_10 :
return L_9 ;
default:
return L_10 ;
}
}
static const char * F_2 ( unsigned int type )
{
switch ( type ) {
case V_11 :
return L_11 ;
case V_12 :
return L_12 ;
case V_13 :
return L_13 ;
default:
return L_10 ;
}
}
static void F_3 ( unsigned int V_1 , int V_14 )
{
if ( V_1 == V_9 )
printf ( L_14 , V_14 ) ;
else if ( V_1 == V_10 )
printf ( L_15 , V_14 ) ;
else if ( V_1 == V_15 )
printf ( L_16 ) ;
else
printf ( L_17 , F_1 ( V_1 ) , V_14 ) ;
}
int F_4 ( const char * V_16 )
{
int V_17 , V_18 , V_19 , * V_20 = NULL , V_21 = 0 ;
struct V_22 * V_23 = NULL ;
char * V_24 ;
unsigned long V_25 , V_26 = 0 ;
T_1 V_27 ;
T_2 * V_28 ;
T_3 * V_29 ;
T_4 V_30 ;
T_5 V_31 ;
T_6 V_32 ;
T_7 * V_33 , * V_34 = NULL , * V_35 = NULL ;
V_36 = V_16 ;
F_5 ( V_37 ) ;
V_17 = F_6 ( V_36 , V_38 ) ;
if ( V_17 == - 1 ) {
perror ( L_18 ) ;
return - 1 ;
}
V_28 = F_7 ( V_17 , V_39 , NULL ) ;
if ( ! V_28 ) {
F_8 ( L_19 ) ;
return - 1 ;
}
if ( F_9 ( V_28 , & V_25 ) ) {
F_8 ( L_20 ) ;
return - 1 ;
}
if ( F_10 ( V_28 , & V_27 ) ) {
F_8 ( L_21 ) ;
return - 1 ;
}
for ( V_19 = 0 ; V_19 < V_25 ; V_19 ++ ) {
V_29 = F_11 ( V_28 , V_19 ) ;
if ( ! V_29 ) {
F_8 ( L_22 ) ;
return - 1 ;
}
if ( ! F_12 ( V_29 , & V_30 ) ) {
F_8 ( L_23 ) ;
return - 1 ;
}
V_24 = F_13 ( V_28 , V_27 , V_30 . V_40 ) ;
if ( ! V_24 ) {
F_8 ( L_24 ) ;
return - 1 ;
}
V_33 = F_14 ( V_29 , NULL ) ;
if ( ! V_33 ) {
F_8 ( L_25 ) ;
return - 1 ;
}
if ( ! strcmp ( V_24 , L_26 ) ) {
V_34 = V_33 ;
} else if ( ! strcmp ( V_24 , L_27 ) ) {
V_23 = V_33 -> V_41 ;
V_21 = V_30 . V_42 ;
} else if ( ! strcmp ( V_24 , L_28 ) ) {
V_20 = V_33 -> V_41 ;
V_26 = V_30 . V_43 ;
} else if ( ! strcmp ( V_24 , L_29 ) ) {
V_35 = V_33 ;
}
}
if ( ! V_34 || ! V_23 || ! V_20 )
return 0 ;
if ( V_21 % sizeof( * V_23 ) != 0 ) {
F_15 ( L_30 ) ;
return - 1 ;
}
V_18 = V_21 / sizeof( * V_23 ) ;
for ( V_19 = 0 ; V_19 < V_18 ; V_19 ++ ) {
if ( V_35 ) {
if ( ! F_16 ( V_35 , V_19 , & V_31 ) ) {
F_8 ( L_31 ) ;
return - 1 ;
}
if ( ! F_17 ( V_34 , F_18 ( V_31 . V_44 ) , & V_32 ) ) {
F_8 ( L_32 ) ;
return - 1 ;
}
V_29 = F_11 ( V_28 , V_32 . V_45 ) ;
if ( ! V_29 ) {
F_8 ( L_22 ) ;
return - 1 ;
}
if ( ! F_12 ( V_29 , & V_30 ) ) {
F_8 ( L_23 ) ;
return - 1 ;
}
V_24 = F_13 ( V_28 , V_27 , V_30 . V_40 ) ;
if ( ! V_24 || ! * V_24 ) {
F_8 ( L_24 ) ;
return - 1 ;
}
printf ( L_33 , V_24 , V_31 . V_46 ) ;
} else {
printf ( L_34 , V_26 + ( V_19 * sizeof( int ) ) + V_20 [ V_19 ] ) ;
}
printf ( L_35 ) ;
F_3 ( V_23 [ V_19 ] . V_47 , V_23 [ V_19 ] . V_48 ) ;
printf ( L_36 ) ;
F_3 ( V_23 [ V_19 ] . V_49 , V_23 [ V_19 ] . V_50 ) ;
printf ( L_37 , F_2 ( V_23 [ V_19 ] . type ) ) ;
}
F_19 ( V_28 ) ;
F_20 ( V_17 ) ;
return 0 ;
}
