static void F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_5 V_6 ;
struct V_7 * V_8 = V_2 -> V_9 -> V_10 ;
int V_11 , V_12 ;
T_1 V_13 ;
F_2 ( V_4 , V_4 -> V_14 , & V_6 , 30303 , 1000 ) ;
if ( V_8 -> V_15 ) {
V_11 = 8 - F_3 ( V_6 . V_11 , 1 , 8 ) ;
V_12 = 18 - F_3 ( V_6 . V_16 , 3 , 18 ) ;
} else {
V_11 = 9 - F_3 ( V_6 . V_11 , 2 , 9 ) ;
V_12 = 15 - F_3 ( V_6 . V_16 , 0 , 15 ) ;
}
V_13 = ( V_12 << 4 ) | V_11 | 0x08 ;
V_8 -> clock [ V_4 -> V_17 ] = V_13 ;
F_4 ( V_13 , V_8 -> V_13 ) ;
}
static void F_5 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_5 V_6 ;
struct V_7 * V_8 = V_2 -> V_9 -> V_10 ;
int V_11 , V_12 ;
T_1 V_13 ;
F_2 ( V_4 , V_4 -> V_14 , & V_6 , 30303 , 1000 ) ;
if ( V_8 -> V_15 ) {
V_11 = 8 - F_3 ( V_6 . V_11 , 1 , 8 ) ;
V_12 = 18 - F_3 ( V_6 . V_16 , 3 , 18 ) ;
} else {
V_11 = 9 - F_3 ( V_6 . V_11 , 2 , 9 ) ;
V_12 = 15 - F_3 ( V_6 . V_16 , 0 , 15 ) ;
}
V_13 = ( V_12 << 4 ) | V_11 | 0x08 ;
V_8 -> clock [ V_4 -> V_17 ] = V_13 ;
F_4 ( V_13 , V_8 -> V_13 ) ;
if ( V_4 -> V_18 != V_19 )
F_4 ( 0x5F , ( V_8 -> V_13 & 0xFFF0 ) + 3 ) ;
}
static unsigned int F_6 ( struct V_20 * V_21 )
{
struct V_1 * V_2 = V_21 -> V_2 ;
struct V_3 * V_4 = V_21 -> V_22 ;
struct V_7 * V_8 = V_2 -> V_9 -> V_10 ;
if ( V_8 -> clock [ V_4 -> V_17 ] != V_8 -> V_23 ) {
if ( V_4 -> V_14 ) {
V_8 -> V_23 = V_8 -> clock [ V_4 -> V_17 ] ;
F_4 ( V_8 -> clock [ V_4 -> V_17 ] , V_8 -> V_13 ) ;
}
}
return F_7 ( V_21 ) ;
}
static unsigned int F_8 ( struct V_3 * V_22 , unsigned char * V_24 ,
unsigned int V_25 , int V_26 )
{
if ( F_9 ( V_22 -> V_27 ) ) {
struct V_1 * V_2 = V_22 -> V_28 -> V_2 ;
int V_29 = V_25 & 3 ;
if ( V_26 == V_30 )
F_10 ( V_2 -> V_31 . V_32 , V_24 , V_25 >> 2 ) ;
else
F_11 ( V_2 -> V_31 . V_32 , V_24 , V_25 >> 2 ) ;
if ( F_12 ( V_29 ) ) {
T_2 V_33 ;
if ( V_26 == V_30 ) {
V_33 = F_13 ( F_14 ( V_2 -> V_31 . V_32 ) ) ;
memcpy ( V_24 + V_25 - V_29 , & V_33 , V_29 ) ;
} else {
memcpy ( & V_33 , V_24 + V_25 - V_29 , V_29 ) ;
F_15 ( F_16 ( V_33 ) , V_2 -> V_31 . V_32 ) ;
}
V_25 += 4 - V_29 ;
}
} else
V_25 = F_17 ( V_22 , V_24 , V_25 , V_26 ) ;
return V_25 ;
}
static T_3 int F_18 ( unsigned long V_34 , int type , unsigned long V_35 , int V_36 , int V_15 )
{
unsigned long V_37 = V_35 + 0x206 ;
struct V_38 * V_39 ;
struct V_40 * V_9 ;
struct V_1 * V_2 ;
void T_4 * V_41 , * V_42 ;
int V_43 ;
V_39 = F_19 ( V_44 , V_45 , NULL , 0 ) ;
if ( F_20 ( V_39 ) )
return F_21 ( V_39 ) ;
V_43 = - V_46 ;
V_41 = F_22 ( & V_39 -> V_22 , V_35 , 8 ) ;
V_42 = F_22 ( & V_39 -> V_22 , V_37 , 1 ) ;
if ( ! V_41 || ! V_42 )
goto V_47;
V_43 = - V_46 ;
V_9 = F_23 ( & V_39 -> V_22 , 1 ) ;
if ( ! V_9 )
goto V_47;
V_2 = V_9 -> V_48 [ 0 ] ;
if ( type == 6580 ) {
V_2 -> V_49 = & V_50 ;
V_2 -> V_51 = V_52 ;
V_2 -> V_53 |= V_54 ;
} else {
V_2 -> V_49 = & V_55 ;
V_2 -> V_51 = V_56 ;
V_2 -> V_53 = V_54 | V_57 ;
}
V_2 -> V_31 . V_58 = V_41 ;
V_2 -> V_31 . V_59 = V_42 ;
V_2 -> V_31 . V_42 = V_42 ;
F_24 ( & V_2 -> V_31 ) ;
F_25 ( V_2 , L_1 , V_35 , V_37 ) ;
V_2 -> V_10 = & V_7 [ V_45 ] ;
V_7 [ V_45 ] . V_13 = V_34 ;
V_7 [ V_45 ] . V_15 = V_15 ;
V_7 [ V_45 ] . V_60 = V_39 ;
F_26 (KERN_INFO DRV_NAMEL_2 , type, io) ;
V_43 = F_27 ( V_9 , V_36 , V_61 , 0 , & V_62 ) ;
if ( V_43 )
goto V_47;
V_63 [ V_45 ++ ] = F_28 ( & V_39 -> V_22 ) ;
return 0 ;
V_47:
F_29 ( V_39 ) ;
return V_43 ;
}
static T_3 int F_30 ( void )
{
unsigned long V_53 ;
static const unsigned long V_64 [ 2 ] = { 0x30 , 0xB0 } ;
static const unsigned long V_65 [ 2 ] = { 0x170 , 0x1F0 } ;
static const int V_66 [ 2 ] = { 14 , 15 } ;
int V_67 = 0 ;
int V_68 ;
if ( V_69 == 0 )
return - V_70 ;
for ( V_68 = 0 ; V_68 < 2 ; V_68 ++ ) {
unsigned long V_34 = V_64 [ V_68 ] ;
T_1 V_71 , V_72 ;
if ( F_31 ( V_34 , 2 , L_3 ) ) {
F_32 ( V_53 ) ;
V_71 = F_33 ( V_34 ) ;
F_34 ( 0x19 , V_34 ) ;
V_72 = F_33 ( V_34 ) ;
F_34 ( V_71 , V_34 ) ;
F_35 ( V_53 ) ;
if ( V_72 == 0x19 )
{
F_36 ( V_34 , 2 ) ;
continue;
}
V_71 = F_33 ( V_34 + 1 ) ;
if ( ( V_71 & 2 ) >> 1 != V_68 ) {
F_36 ( V_34 , 2 ) ;
continue;
}
if ( ( V_71 & 0xF0 ) == 0xC0 ) {
if ( V_71 & 8 ) {
F_36 ( V_34 , 2 ) ;
continue;
}
if ( F_18 ( V_34 , 6500 , V_65 [ V_71 & 0x01 ] , V_66 [ V_71 & 0x01 ] , V_71 & 0x04 ) == 0 )
V_67 ++ ;
}
if ( ( ( V_71 & 0xF0 ) == 0xA0 ) || ( V_71 & 0xF0 ) == 0x50 ) {
if ( ! F_31 ( V_34 + 2 , 2 , L_3 ) )
{
F_36 ( V_34 , 2 ) ;
continue;
}
V_72 = F_37 ( V_34 + 3 ) ;
if ( V_72 & 1 ) {
if ( F_18 ( V_34 , 6580 , V_65 [ V_71 & 0x01 ] , V_66 [ V_71 & 0x01 ] , V_71 & 0x04 ) == 0 )
V_67 ++ ;
} else {
if ( F_18 ( V_34 , 6580 , 0x1F0 , 14 , V_71 & 0x04 ) == 0 )
V_67 ++ ;
if ( F_18 ( V_34 + 2 , 6580 , 0x170 , 15 , V_71 & 0x04 ) == 0 )
V_67 ++ ;
}
}
}
}
if ( V_67 != 0 )
return 0 ;
return - V_70 ;
}
static T_5 void F_38 ( void )
{
int V_68 ;
for ( V_68 = 0 ; V_68 < V_45 ; V_68 ++ ) {
F_39 ( V_63 [ V_68 ] ) ;
F_36 ( V_7 [ V_68 ] . V_13 , 2 ) ;
F_29 ( V_7 [ V_68 ] . V_60 ) ;
}
}
