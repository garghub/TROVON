void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
F_3 ( & V_2 -> V_5 ) ;
F_3 ( & V_4 -> V_6 ) ;
F_3 ( & V_4 -> V_7 ) ;
F_3 ( & V_4 -> V_8 ) ;
F_3 ( & V_4 -> V_9 ) ;
}
void F_4 ( struct V_1 * V_2 , unsigned short V_10 )
{
struct V_11 * V_12 ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_13 = V_4 -> V_14 -> V_15 ? V_16 : V_17 ;
if ( V_4 -> V_18 != V_10 )
while ( F_5 ( & V_4 -> V_6 ) && V_4 -> V_18 != V_10 ) {
V_12 = F_6 ( & V_4 -> V_6 ) ;
F_7 ( V_12 ) ;
V_4 -> V_18 = ( V_4 -> V_18 + 1 ) % V_13 ;
}
}
void F_8 ( struct V_1 * V_2 )
{
struct V_11 * V_12 , * V_19 = NULL ;
while ( ( V_12 = F_6 ( & F_2 ( V_2 ) -> V_6 ) ) != NULL ) {
if ( ! V_19 )
F_9 ( & V_2 -> V_5 , V_12 ) ;
else
F_10 ( V_19 , V_12 , & V_2 -> V_5 ) ;
V_19 = V_12 ;
}
}
int F_11 ( struct V_1 * V_2 , unsigned short V_10 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
unsigned short V_20 = V_4 -> V_18 ;
int V_13 = V_4 -> V_14 -> V_15 ? V_16 : V_17 ;
while ( V_20 != V_4 -> V_21 ) {
if ( V_10 == V_20 )
return 1 ;
V_20 = ( V_20 + 1 ) % V_13 ;
}
return V_10 == V_4 -> V_21 ? 1 : 0 ;
}
void F_12 ( struct V_1 * V_2 , int V_22 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_11 * V_12 ;
unsigned char * V_23 ;
unsigned char V_24 [ V_25 ] ;
unsigned char V_26 [ 1 + V_27 ] ;
unsigned char V_28 , V_29 ;
int V_30 = V_31 + V_32 ;
switch ( V_22 ) {
case V_33 :
V_30 += 1 + V_27 + V_25 + V_34 ;
break;
case V_35 :
if ( V_4 -> V_24 . V_36 & 0x80 ) {
V_30 += 1 + V_25 + V_34 ;
} else {
V_30 += 1 + V_25 ;
}
break;
case V_37 :
case V_38 :
V_30 += 2 ;
break;
case V_39 :
case V_40 :
case V_41 :
case V_42 :
case V_43 :
case V_44 :
break;
default:
F_13 ( L_1 , V_22 ) ;
return;
}
if ( ( V_12 = F_14 ( V_30 , V_45 ) ) == NULL )
return;
F_15 ( V_12 , V_31 ) ;
V_23 = F_16 ( V_12 , 2 ) ;
V_28 = ( V_4 -> V_46 >> 8 ) & 0x0F ;
V_29 = ( V_4 -> V_46 >> 0 ) & 0xFF ;
if ( V_4 -> V_14 -> V_15 ) {
* V_23 ++ = V_28 | V_47 ;
* V_23 ++ = V_29 ;
} else {
* V_23 ++ = V_28 | V_48 ;
* V_23 ++ = V_29 ;
}
switch ( V_22 ) {
case V_33 :
V_23 = F_16 ( V_12 , 1 ) ;
* V_23 ++ = V_33 ;
V_30 = F_17 ( V_26 , & V_4 -> V_49 ,
& V_4 -> V_50 ) ;
F_18 ( V_12 , V_26 , V_30 ) ;
V_30 = F_19 ( V_24 ,
& V_4 -> V_24 ,
& V_4 -> V_51 ,
V_4 -> V_14 -> V_52 ) ;
F_18 ( V_12 , V_24 , V_30 ) ;
F_18 ( V_12 , V_4 -> V_53 . V_54 ,
V_4 -> V_53 . V_55 ) ;
V_4 -> V_53 . V_55 = 0 ;
break;
case V_35 :
V_23 = F_16 ( V_12 , 2 ) ;
* V_23 ++ = V_35 ;
* V_23 ++ = 0x00 ;
V_30 = F_19 ( V_24 ,
& V_4 -> V_24 ,
& V_4 -> V_51 ,
V_4 -> V_56 ) ;
F_18 ( V_12 , V_24 , V_30 ) ;
if( V_4 -> V_24 . V_36 & 0x80 ) {
F_18 ( V_12 ,
V_4 -> V_53 . V_54 ,
V_4 -> V_53 . V_55 ) ;
}
V_4 -> V_53 . V_55 = 0 ;
break;
case V_37 :
V_23 = F_16 ( V_12 , 3 ) ;
* V_23 ++ = V_22 ;
* V_23 ++ = V_4 -> V_57 . V_58 ;
* V_23 ++ = V_4 -> V_57 . V_59 ;
break;
case V_38 :
V_23 = F_16 ( V_12 , 3 ) ;
* V_23 ++ = V_22 ;
* V_23 ++ = 0x00 ;
* V_23 ++ = 0x00 ;
break;
case V_39 :
case V_40 :
case V_41 :
if ( V_4 -> V_14 -> V_15 ) {
V_23 = F_16 ( V_12 , 2 ) ;
* V_23 ++ = V_22 ;
* V_23 ++ = ( V_4 -> V_60 << 1 ) & 0xFE ;
} else {
V_23 = F_16 ( V_12 , 1 ) ;
* V_23 = V_22 ;
* V_23 ++ |= ( V_4 -> V_60 << 5 ) & 0xE0 ;
}
break;
case V_42 :
case V_43 :
case V_44 :
V_23 = F_16 ( V_12 , 1 ) ;
* V_23 = V_22 ;
break;
}
F_20 ( V_12 , V_4 -> V_14 ) ;
}
int F_21 ( struct V_1 * V_2 , struct V_11 * V_12 , int * V_61 , int * V_10 , int * V_62 ,
int * V_63 , int * V_64 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
unsigned char * V_65 ;
if ( ! F_22 ( V_12 , V_66 ) )
return V_67 ;
V_65 = V_12 -> V_68 ;
* V_61 = * V_10 = * V_62 = * V_63 = * V_64 = 0 ;
switch ( V_65 [ 2 ] ) {
case V_33 :
case V_35 :
case V_37 :
case V_42 :
case V_69 :
case V_43 :
case V_38 :
case V_44 :
case V_70 :
case V_71 :
case V_72 :
case V_73 :
case V_74 :
return V_65 [ 2 ] ;
}
if ( V_4 -> V_14 -> V_15 ) {
if ( V_65 [ 2 ] == V_39 ||
V_65 [ 2 ] == V_40 ||
V_65 [ 2 ] == V_41 ) {
if ( ! F_22 ( V_12 , V_32 ) )
return V_67 ;
V_65 = V_12 -> V_68 ;
* V_10 = ( V_65 [ 3 ] >> 1 ) & 0x7F ;
return V_65 [ 2 ] ;
}
} else {
if ( ( V_65 [ 2 ] & 0x1F ) == V_39 ||
( V_65 [ 2 ] & 0x1F ) == V_40 ||
( V_65 [ 2 ] & 0x1F ) == V_41 ) {
* V_10 = ( V_65 [ 2 ] >> 5 ) & 0x07 ;
return V_65 [ 2 ] & 0x1F ;
}
}
if ( V_4 -> V_14 -> V_15 ) {
if ( ( V_65 [ 2 ] & 0x01 ) == V_75 ) {
if ( ! F_22 ( V_12 , V_32 ) )
return V_67 ;
V_65 = V_12 -> V_68 ;
* V_62 = ( V_65 [ 0 ] & V_76 ) == V_76 ;
* V_63 = ( V_65 [ 0 ] & V_77 ) == V_77 ;
* V_64 = ( V_65 [ 3 ] & V_78 ) == V_78 ;
* V_10 = ( V_65 [ 3 ] >> 1 ) & 0x7F ;
* V_61 = ( V_65 [ 2 ] >> 1 ) & 0x7F ;
return V_75 ;
}
} else {
if ( ( V_65 [ 2 ] & 0x01 ) == V_75 ) {
* V_62 = ( V_65 [ 0 ] & V_76 ) == V_76 ;
* V_63 = ( V_65 [ 0 ] & V_77 ) == V_77 ;
* V_64 = ( V_65 [ 2 ] & V_79 ) == V_79 ;
* V_10 = ( V_65 [ 2 ] >> 5 ) & 0x07 ;
* V_61 = ( V_65 [ 2 ] >> 1 ) & 0x07 ;
return V_75 ;
}
}
F_23 ( L_2 ,
V_65 [ 0 ] , V_65 [ 1 ] , V_65 [ 2 ] ) ;
return V_67 ;
}
void F_24 ( struct V_1 * V_2 , int V_80 , unsigned char V_58 ,
unsigned char V_59 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
F_1 ( V_2 ) ;
F_25 ( V_2 ) ;
V_4 -> V_46 = 0 ;
V_4 -> V_81 = V_82 ;
V_4 -> V_57 . V_58 = V_58 ;
V_4 -> V_57 . V_59 = V_59 ;
V_2 -> V_83 = V_84 ;
V_2 -> V_85 = V_80 ;
V_2 -> V_86 |= V_87 ;
if ( ! F_26 ( V_2 , V_88 ) ) {
V_2 -> V_89 ( V_2 ) ;
F_27 ( V_2 , V_88 ) ;
}
}
void F_28 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
if ( F_29 ( & V_2 -> V_90 ) < ( V_2 -> V_91 >> 1 ) &&
( V_4 -> V_92 & V_93 ) ) {
V_4 -> V_92 &= ~ V_93 ;
V_4 -> V_92 &= ~ V_94 ;
V_4 -> V_95 = V_4 -> V_60 ;
F_12 ( V_2 , V_39 ) ;
F_25 ( V_2 ) ;
}
}
