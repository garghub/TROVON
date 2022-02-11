T_1 * F_1 ( struct V_1 * V_2 , int V_3 , T_2 * V_4 , T_2 * V_5 , T_3 * V_6 , struct V_7 * V_8 )
{
T_4 * T_4 ;
T_1 * V_9 ;
if ( V_3 == 0 ) {
if ( ( T_4 = F_2 ( V_8 ) ) == NULL )
return NULL ;
V_3 = T_4 -> V_10 [ V_11 ] ;
}
if ( ( V_9 = F_3 ( V_4 , V_5 , V_6 , V_8 ) ) != NULL ) {
F_4 ( V_9 , V_3 , V_2 ) ;
return V_9 ;
}
if ( ( T_4 = F_2 ( V_8 ) ) == NULL )
return NULL ;
if ( ( V_9 = F_5 () ) == NULL )
return NULL ;
F_6 ( V_9 , T_4 ) ;
V_9 -> V_12 = * V_4 ;
V_9 -> V_13 = * V_5 ;
if ( V_6 != NULL ) {
V_9 -> V_14 = F_7 ( V_6 , sizeof( * V_6 ) , V_15 ) ;
if ( V_9 -> V_14 == NULL ) {
F_8 ( V_9 ) ;
return NULL ;
}
}
switch ( V_9 -> T_4 -> V_10 [ V_16 ] ) {
case V_17 :
case V_18 :
F_9 ( V_9 ) ;
break;
#ifdef F_10
case V_19 :
if ( T_4 -> V_20 . V_21 )
F_11 ( V_9 ) ;
else
F_9 ( V_9 ) ;
break;
#endif
}
F_12 ( V_9 ) ;
F_13 ( V_9 ) ;
V_9 -> V_22 = V_23 ;
F_14 ( V_9 ) ;
F_4 ( V_9 , V_3 , V_2 ) ;
return V_9 ;
}
void F_4 ( T_1 * V_9 , int V_3 , struct V_1 * V_2 )
{
struct V_1 * V_24 ;
unsigned char * V_25 ;
int V_26 , V_27 , V_28 , V_29 , V_30 = 1 ;
if ( V_3 < 16 ) {
F_15 ( 1 ) ;
F_16 ( V_2 ) ;
return;
}
if ( ( V_2 -> V_27 - 1 ) > V_3 ) {
if ( * V_2 -> V_31 == V_32 ) {
F_17 ( V_2 , 1 ) ;
V_29 = 0 ;
} else {
V_3 -= 2 ;
V_29 = 1 ;
}
V_28 = V_2 -> V_27 / V_3 ;
if ( V_2 -> V_27 % V_3 == 0 ) V_28 -- ;
V_26 = F_18 ( V_2 ) ;
while ( V_2 -> V_27 > 0 ) {
F_19 ( & V_33 ) ;
if ( ( V_24 = F_20 ( V_3 + 2 + V_26 , V_15 ) ) == NULL ) {
F_21 ( & V_33 ) ;
F_22 ( V_34 L_1 ) ;
return;
}
if ( V_2 -> V_35 != NULL )
F_23 ( V_24 , V_2 -> V_35 ) ;
F_21 ( & V_33 ) ;
V_27 = ( V_3 > V_2 -> V_27 ) ? V_2 -> V_27 : V_3 ;
if ( V_29 == 1 ) {
F_24 ( V_24 , V_26 + 2 ) ;
F_25 ( V_24 ,
F_26 ( V_2 ) ) ;
F_27 ( V_2 , F_28 ( V_24 , V_27 ) , V_27 ) ;
V_25 = F_29 ( V_24 , 2 ) ;
* V_25 ++ = V_36 ;
* V_25 = V_28 -- ;
if ( V_30 ) {
* V_25 |= V_37 ;
V_30 = 0 ;
}
} else {
F_24 ( V_24 , V_26 + 1 ) ;
F_25 ( V_24 ,
F_26 ( V_2 ) ) ;
F_27 ( V_2 , F_28 ( V_24 , V_27 ) , V_27 ) ;
V_25 = F_29 ( V_24 , 1 ) ;
* V_25 = V_32 ;
}
F_17 ( V_2 , V_27 ) ;
F_30 ( & V_9 -> V_38 , V_24 ) ;
}
F_16 ( V_2 ) ;
} else {
F_30 ( & V_9 -> V_38 , V_2 ) ;
}
switch ( V_9 -> T_4 -> V_10 [ V_16 ] ) {
case V_17 :
case V_18 :
F_31 ( V_9 ) ;
break;
#ifdef F_10
case V_19 :
if ( ! V_9 -> T_4 -> V_20 . V_21 ) F_31 ( V_9 ) ;
break;
#endif
}
}
static void F_32 ( T_1 * V_9 , struct V_1 * V_2 , int V_39 )
{
unsigned char * V_40 ;
if ( V_2 == NULL )
return;
F_33 ( V_2 ) ;
if ( V_9 -> V_41 == V_42 ) {
V_40 = F_29 ( V_2 , 1 ) ;
* V_40 = V_43 ;
* V_40 |= ( V_39 ) ? V_44 : 0 ;
* V_40 |= ( V_9 -> V_45 << 5 ) ;
* V_40 |= ( V_9 -> V_46 << 1 ) ;
} else {
V_40 = F_29 ( V_2 , 2 ) ;
V_40 [ 0 ] = V_43 ;
V_40 [ 0 ] |= ( V_9 -> V_46 << 1 ) ;
V_40 [ 1 ] = ( V_39 ) ? V_47 : 0 ;
V_40 [ 1 ] |= ( V_9 -> V_45 << 1 ) ;
}
F_34 ( V_9 ) ;
F_35 ( V_9 , V_2 , V_48 ) ;
}
void F_31 ( T_1 * V_9 )
{
struct V_1 * V_2 , * V_24 ;
int V_49 = 1 ;
unsigned short V_50 , V_51 , V_52 ;
if ( V_9 -> V_22 != V_53 && V_9 -> V_22 != V_54 )
return;
if ( V_9 -> V_55 & V_56 )
return;
if ( F_36 ( & V_9 -> V_38 ) == NULL )
return;
V_50 = ( F_36 ( & V_9 -> V_57 ) == NULL ) ? V_9 -> V_58 : V_9 -> V_46 ;
V_51 = ( V_9 -> V_58 + V_9 -> V_59 ) % V_9 -> V_41 ;
if ( V_50 == V_51 )
return;
V_2 = F_37 ( & V_9 -> V_38 ) ;
if ( ! V_2 )
return;
V_9 -> V_46 = V_50 ;
do {
if ( ( V_24 = F_38 ( V_2 , V_15 ) ) == NULL ) {
F_39 ( & V_9 -> V_38 , V_2 ) ;
break;
}
if ( V_2 -> V_35 != NULL )
F_23 ( V_24 , V_2 -> V_35 ) ;
V_52 = ( V_9 -> V_46 + 1 ) % V_9 -> V_41 ;
V_49 = ( V_52 == V_51 ) ;
switch ( V_9 -> T_4 -> V_10 [ V_16 ] ) {
case V_17 :
case V_18 :
F_32 ( V_9 , V_24 , ( V_49 ) ? V_60 : V_61 ) ;
break;
#ifdef F_10
case V_19 :
F_32 ( V_9 , V_24 , V_61 ) ;
break;
#endif
}
V_9 -> V_46 = V_52 ;
F_30 ( & V_9 -> V_57 , V_2 ) ;
} while ( ! V_49 && ( V_2 = F_37 ( & V_9 -> V_38 ) ) != NULL );
V_9 -> V_55 &= ~ V_62 ;
if ( ! F_40 ( V_9 ) ) {
F_41 ( V_9 ) ;
F_42 ( V_9 ) ;
F_43 ( V_9 ) ;
}
}
void F_35 ( T_1 * V_9 , struct V_1 * V_2 , int type )
{
struct V_1 * V_24 ;
unsigned char * V_63 ;
int V_64 ;
if ( V_9 -> T_4 == NULL ) {
F_44 ( V_9 , V_65 ) ;
return;
}
V_64 = F_45 ( V_9 -> V_14 ) ;
if ( F_18 ( V_2 ) < V_64 ) {
if ( ( V_24 = F_46 ( V_2 , V_64 ) ) == NULL ) {
F_22 ( V_34 L_2 ) ;
F_16 ( V_2 ) ;
return;
}
if ( V_2 -> V_35 != NULL )
F_23 ( V_24 , V_2 -> V_35 ) ;
F_47 ( V_2 ) ;
V_2 = V_24 ;
}
V_63 = F_29 ( V_2 , V_64 ) ;
F_48 ( V_63 , & V_9 -> V_12 , & V_9 -> V_13 , V_9 -> V_14 , type , V_9 -> V_41 ) ;
F_49 ( V_2 , V_9 -> T_4 -> V_8 ) ;
}
void F_49 ( struct V_1 * V_2 , struct V_7 * V_8 )
{
unsigned char * V_63 ;
V_2 -> V_66 = F_50 ( V_2 , F_51 ( V_8 ) ) ;
V_63 = F_29 ( V_2 , 1 ) ;
* V_63 = 0x00 ;
F_52 ( V_2 ) ;
}
int F_53 ( T_1 * V_9 , unsigned short V_67 )
{
if ( V_9 -> V_46 == V_67 ) {
F_54 ( V_9 , V_67 ) ;
F_55 ( V_9 ) ;
F_56 ( V_9 ) ;
F_57 ( V_9 ) ;
return 1 ;
} else {
if ( V_9 -> V_58 != V_67 ) {
F_54 ( V_9 , V_67 ) ;
F_42 ( V_9 ) ;
F_43 ( V_9 ) ;
return 1 ;
}
}
return 0 ;
}
