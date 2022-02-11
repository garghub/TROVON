static int F_1 ( struct V_1 * V_2 , int V_3 ,
int V_4 , int V_5 )
{
struct V_6 * V_7 ;
struct V_8 * V_9 = NULL ;
int V_10 = V_11 [ V_3 ] ;
if ( ! V_10 )
return - V_12 ;
if ( V_2 -> V_13 -> V_14 >= 0x0010 ) {
if ( V_10 == 1 ) {
if ( ! ( V_10 = F_2 ( V_2 -> V_13 , 2 ) ) )
return - V_12 ;
}
} else {
if ( V_10 == 1 ) {
for ( V_10 = 0x201 ; V_10 <= 0x205 ; V_10 ++ ) {
if ( V_10 == 0x203 )
continue;
if ( ( V_9 = F_3 ( V_10 , 1 , L_1 ) ) != NULL )
break;
}
if ( ! V_9 ) {
F_4 ( V_2 -> V_15 -> V_3 ,
L_2 ) ;
return - V_16 ;
}
}
switch ( V_10 ) {
case 0x201 : V_5 |= 0 << 6 ; break;
case 0x202 : V_5 |= 1 << 6 ; break;
case 0x204 : V_5 |= 2 << 6 ; break;
case 0x205 : V_5 |= 3 << 6 ; break;
default:
F_4 ( V_2 -> V_15 -> V_3 ,
L_3 , V_10 ) ;
return - V_17 ;
}
}
if ( ! V_9 && ! ( V_9 = F_3 ( V_10 , 1 , L_1 ) ) ) {
F_4 ( V_2 -> V_15 -> V_3 ,
L_4 , V_10 ) ;
return - V_16 ;
}
V_2 -> V_6 = V_7 = F_5 () ;
if ( ! V_7 ) {
F_4 ( V_2 -> V_15 -> V_3 ,
L_5 ) ;
F_6 ( V_9 ) ;
return - V_18 ;
}
F_7 ( V_7 , L_6 ) ;
F_8 ( V_7 , L_7 , F_9 ( V_2 -> V_13 ) ) ;
F_10 ( V_7 , & V_2 -> V_13 -> V_3 ) ;
V_7 -> V_19 = V_10 ;
F_11 ( V_7 , V_9 ) ;
if ( V_2 -> V_13 -> V_14 >= 0x0010 )
F_12 ( V_2 -> V_13 , V_20 , V_10 ) ;
F_12 ( V_2 -> V_13 , V_21 , V_4 | V_22 ) ;
F_12 ( V_2 -> V_13 , V_23 , V_5 ) ;
F_13 ( V_2 -> V_6 ) ;
return 0 ;
}
void F_14 ( struct V_1 * V_2 )
{
if ( V_2 -> V_6 ) {
struct V_8 * V_9 = F_15 ( V_2 -> V_6 ) ;
F_16 ( V_2 -> V_6 ) ;
V_2 -> V_6 = NULL ;
F_6 ( V_9 ) ;
}
}
static inline int F_1 ( struct V_1 * V_2 , int V_3 , int V_24 , int V_25 ) { return - V_26 ; }
void F_14 ( struct V_1 * V_2 ) { }
static int F_17 ( struct V_27 * V_13 ,
const struct V_28 * V_29 )
{
static int V_3 ;
struct V_30 * V_15 ;
struct V_8 * V_31 = NULL ;
struct V_8 * V_32 = NULL ;
struct V_1 * V_2 ;
struct V_33 * V_34 ;
const char * V_35 , * V_36 ;
int V_37 ;
T_1 V_4 , V_5 , V_38 ;
if ( V_3 >= V_39 )
return - V_12 ;
if ( ! V_40 [ V_3 ] ) {
V_3 ++ ;
return - V_41 ;
}
V_37 = F_18 ( & V_13 -> V_3 , V_42 [ V_3 ] , V_43 [ V_3 ] , V_44 ,
0 , & V_15 ) ;
if ( V_37 < 0 )
return V_37 ;
switch ( V_29 -> V_14 ) {
case 0x0004 : V_35 = L_8 ; V_36 = L_9 ; break;
case 0x000d : V_35 = L_10 ; V_36 = L_9 ; break;
case 0x000a : V_35 = L_11 ; V_36 = L_12 ; break;
case 0x000c : V_35 = L_13 ; V_36 = L_12 ; break;
case 0x0010 : V_35 = L_14 ; V_36 = L_15 ; break;
case 0x0012 : V_35 = L_16 ; V_36 = L_17 ; break;
default: V_36 = V_35 = L_18 ; break;
}
V_4 = 0 ;
V_5 = 0x0800 ;
if ( V_29 -> V_14 >= 0x0010 ) {
if ( V_45 [ V_3 ] == 1 ) {
V_45 [ V_3 ] = F_2 ( V_13 , 1 ) ;
}
if ( V_45 [ V_3 ] > 0 &&
( V_31 = F_3 ( V_45 [ V_3 ] , 4 , L_19 ) ) != NULL ) {
V_4 |= V_46 ;
F_12 ( V_13 , V_47 , V_45 [ V_3 ] ) ;
}
if ( V_48 [ V_3 ] == 1 ) {
V_48 [ V_3 ] = F_2 ( V_13 , 1 ) + 0x20 ;
}
if ( V_48 [ V_3 ] > 0 &&
( V_32 = F_3 ( V_48 [ V_3 ] , 2 , L_20 ) ) != NULL ) {
V_4 |= V_49 ;
F_12 ( V_13 , V_50 , V_48 [ V_3 ] ) ;
}
} else {
switch ( V_45 [ V_3 ] ) {
case 0x388 : V_5 |= 0 ; break;
case 0x398 : V_5 |= 1 ; break;
case 0x3a0 : V_5 |= 2 ; break;
case 0x3a8 : V_5 |= 3 ; break;
default: V_45 [ V_3 ] = 0 ; break;
}
if ( V_45 [ V_3 ] > 0 &&
( V_31 = F_3 ( V_45 [ V_3 ] , 4 , L_19 ) ) != NULL ) {
V_4 |= V_46 ;
} else {
V_5 &= ~ V_51 ;
V_45 [ V_3 ] = 0 ;
}
switch ( V_48 [ V_3 ] ) {
case 0x330 : V_5 |= 0 << 4 ; break;
case 0x300 : V_5 |= 1 << 4 ; break;
case 0x332 : V_5 |= 2 << 4 ; break;
case 0x334 : V_5 |= 3 << 4 ; break;
default: V_48 [ V_3 ] = 0 ; break;
}
if ( V_48 [ V_3 ] > 0 &&
( V_32 = F_3 ( V_48 [ V_3 ] , 2 , L_20 ) ) != NULL ) {
V_4 |= V_49 ;
} else {
V_5 &= ~ V_52 ;
V_48 [ V_3 ] = 0 ;
}
}
if ( V_32 ) {
V_4 |= V_53 ;
V_5 |= V_54 ;
}
F_19 ( V_13 , V_21 , & V_38 ) ;
F_12 ( V_13 , V_21 , V_4 ) ;
F_12 ( V_13 , V_23 , V_5 ) ;
if ( ( V_37 = F_20 ( V_15 , V_13 ,
V_38 ,
& V_2 ) ) < 0 ) {
F_21 ( V_15 ) ;
F_6 ( V_32 ) ;
F_6 ( V_31 ) ;
return V_37 ;
}
V_2 -> V_31 = V_31 ;
V_2 -> V_32 = V_32 ;
V_15 -> V_55 = V_2 ;
strcpy ( V_15 -> V_56 , V_35 ) ;
sprintf ( V_15 -> V_57 , L_21 , V_36 , V_35 ) ;
sprintf ( V_15 -> V_58 , L_22 ,
V_15 -> V_57 ,
V_2 -> V_59 ,
V_2 -> V_60 ) ;
if ( ( V_37 = F_22 ( V_2 , 0 , NULL ) ) < 0 ) {
F_21 ( V_15 ) ;
return V_37 ;
}
if ( ( V_37 = F_23 ( V_2 , 1 , NULL ) ) < 0 ) {
F_21 ( V_15 ) ;
return V_37 ;
}
V_37 = F_24 ( V_2 , V_61 [ V_3 ] ) ;
if ( V_37 < 0 ) {
F_21 ( V_15 ) ;
return V_37 ;
}
if ( V_2 -> V_62 -> V_63 & V_64 ) {
V_37 = F_25 ( V_2 , 2 , NULL ) ;
if ( V_37 < 0 ) {
F_21 ( V_15 ) ;
return V_37 ;
}
V_37 = F_26 ( V_2 , 3 , NULL ) ;
if ( V_37 < 0 ) {
F_21 ( V_15 ) ;
return V_37 ;
}
}
if ( ( V_37 = F_27 ( V_2 , 0 ) ) < 0 ) {
F_21 ( V_15 ) ;
return V_37 ;
}
if ( V_2 -> V_32 ) {
if ( ( V_37 = F_28 ( V_15 , 0 , V_65 ,
V_48 [ V_3 ] ,
V_66 |
V_67 ,
- 1 , & V_2 -> V_68 ) ) < 0 ) {
F_29 ( V_15 -> V_3 ,
L_23 ,
V_48 [ V_3 ] ) ;
V_4 &= ~ V_53 ;
F_12 ( V_13 , V_21 , V_4 ) ;
}
}
if ( V_2 -> V_31 ) {
if ( ( V_37 = F_30 ( V_15 ,
V_45 [ V_3 ] ,
V_45 [ V_3 ] + 2 ,
V_69 , 1 , & V_34 ) ) < 0 ) {
F_29 ( V_15 -> V_3 ,
L_24 ,
V_45 [ V_3 ] ) ;
V_4 &= ~ V_46 ;
F_12 ( V_13 , V_21 , V_4 ) ;
} else if ( ( V_37 = F_31 ( V_34 , 0 , 1 , NULL ) ) < 0 ) {
F_21 ( V_15 ) ;
F_4 ( V_15 -> V_3 , L_25 ) ;
return V_37 ;
}
}
F_1 ( V_2 , V_3 , V_4 , V_5 ) ;
if ( ( V_37 = F_32 ( V_15 ) ) < 0 ) {
F_21 ( V_15 ) ;
return V_37 ;
}
F_33 ( V_13 , V_15 ) ;
V_3 ++ ;
return 0 ;
}
static void F_34 ( struct V_27 * V_13 )
{
F_21 ( F_35 ( V_13 ) ) ;
}
