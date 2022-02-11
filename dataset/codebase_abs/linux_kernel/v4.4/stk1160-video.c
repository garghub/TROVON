static inline void F_1 ( struct V_1 * V_2 ,
int V_3 , int V_4 )
{
char * V_5 = L_1 ;
switch ( V_4 ) {
case - V_6 :
V_5 = L_2 ;
break;
case - V_7 :
V_5 = L_3 ;
break;
case - V_8 :
V_5 = L_4 ;
break;
case - V_9 :
V_5 = L_5 ;
break;
case - V_10 :
V_5 = L_6 ;
break;
case - V_11 :
V_5 = L_7 ;
break;
case - V_12 :
V_5 = L_8 ;
break;
case - V_13 :
V_5 = L_9 ;
break;
}
if ( V_3 < 0 )
F_2 ( V_14 L_10 ,
V_4 , V_5 ) ;
else
F_2 ( V_15 L_11 ,
V_3 , V_4 , V_5 ) ;
}
static inline
struct V_16 * F_3 ( struct V_1 * V_2 )
{
struct V_16 * V_17 = NULL ;
unsigned long V_18 = 0 ;
F_4 ( V_2 -> V_19 . V_17 ) ;
F_5 ( & V_2 -> V_20 , V_18 ) ;
if ( ! F_6 ( & V_2 -> V_21 ) ) {
V_17 = F_7 ( & V_2 -> V_21 ,
struct V_16 , V_22 ) ;
F_8 ( & V_17 -> V_22 ) ;
}
F_9 ( & V_2 -> V_20 , V_18 ) ;
return V_17 ;
}
static inline
void F_10 ( struct V_1 * V_2 )
{
struct V_16 * V_17 = V_2 -> V_19 . V_17 ;
V_17 -> V_23 . V_24 = V_2 -> V_24 ++ ;
V_17 -> V_23 . V_25 = V_26 ;
V_17 -> V_23 . V_27 . V_28 [ 0 ] . V_29 = V_17 -> V_29 ;
F_11 ( & V_17 -> V_23 . V_30 ) ;
F_12 ( & V_17 -> V_23 . V_27 , 0 , V_17 -> V_29 ) ;
F_13 ( & V_17 -> V_23 . V_27 , V_31 ) ;
V_2 -> V_19 . V_17 = NULL ;
}
static inline
void F_14 ( struct V_1 * V_2 , T_1 * V_32 , int V_33 )
{
int V_34 , V_35 , V_36 ;
int V_37 = V_2 -> V_38 * 2 ;
struct V_16 * V_17 = V_2 -> V_19 . V_17 ;
T_1 * V_39 = V_17 -> V_40 ;
int V_41 ;
V_33 -= 4 ;
V_32 += 4 ;
V_41 = V_33 ;
V_34 = V_17 -> V_42 / V_37 ;
V_35 = V_17 -> V_42 % V_37 ;
if ( ! V_17 -> V_43 )
V_39 += V_37 ;
V_39 += V_34 * V_37 * 2 + V_35 ;
if ( V_41 < ( V_37 - V_35 ) )
V_36 = V_41 ;
else
V_36 = V_37 - V_35 ;
if ( V_36 > V_17 -> V_29 - V_17 -> V_44 ) {
V_36 = V_17 -> V_29 - V_17 -> V_44 ;
V_41 = V_36 ;
}
if ( V_36 == 0 || V_41 == 0 )
return;
if ( V_36 < 0 ) {
F_15 ( L_12 ) ;
return;
}
if ( ( unsigned long ) V_39 + V_36 >
( unsigned long ) V_17 -> V_40 + V_17 -> V_44 ) {
F_2 ( V_14 L_13 ) ;
return;
}
memcpy ( V_39 , V_32 , V_36 ) ;
V_17 -> V_29 += V_36 ;
V_17 -> V_42 += V_36 ;
V_41 -= V_36 ;
while ( V_41 > 0 ) {
V_39 += V_36 + V_37 ;
V_32 += V_36 ;
if ( V_41 < V_37 )
V_36 = V_41 ;
else
V_36 = V_37 ;
if ( V_36 > V_17 -> V_29 - V_17 -> V_44 ) {
V_36 = V_17 -> V_29 - V_17 -> V_44 ;
V_41 = V_36 ;
}
if ( V_36 == 0 || V_41 == 0 )
return;
if ( V_36 < 0 ) {
F_2 ( V_14 L_14 ) ;
return;
}
if ( ( unsigned long ) V_39 + V_36 >
( unsigned long ) V_17 -> V_40 + V_17 -> V_44 ) {
F_2 ( V_14 L_13 ) ;
return;
}
memcpy ( V_39 , V_32 , V_36 ) ;
V_41 -= V_36 ;
V_17 -> V_29 += V_36 ;
V_17 -> V_42 += V_36 ;
}
}
static void F_16 ( struct V_1 * V_2 , struct V_45 * V_45 )
{
int V_46 , V_33 , V_4 ;
T_1 * V_47 ;
if ( ! V_2 ) {
F_17 ( L_15 , V_48 ) ;
return;
}
if ( V_45 -> V_4 < 0 ) {
F_1 ( V_2 , - 1 , V_45 -> V_4 ) ;
return;
}
for ( V_46 = 0 ; V_46 < V_45 -> V_49 ; V_46 ++ ) {
V_4 = V_45 -> V_50 [ V_46 ] . V_4 ;
if ( V_4 < 0 ) {
F_1 ( V_2 , V_46 , V_4 ) ;
continue;
}
V_47 = V_45 -> V_51 + V_45 -> V_50 [ V_46 ] . V_52 ;
V_33 = V_45 -> V_50 [ V_46 ] . V_53 ;
if ( V_33 <= 4 )
continue;
if ( V_47 [ 0 ] == 0xc0 ) {
if ( V_2 -> V_19 . V_17 != NULL )
F_10 ( V_2 ) ;
V_2 -> V_19 . V_17 = F_3 ( V_2 ) ;
if ( V_2 -> V_19 . V_17 == NULL )
return;
}
if ( V_2 -> V_19 . V_17 == NULL )
continue;
if ( V_47 [ 0 ] == 0xc0 || V_47 [ 0 ] == 0x80 ) {
V_2 -> V_19 . V_17 -> V_43 = * V_47 & 0x40 ;
V_2 -> V_19 . V_17 -> V_42 = 0 ;
continue;
}
F_14 ( V_2 , V_47 , V_33 ) ;
}
}
static void F_18 ( struct V_45 * V_45 )
{
int V_46 , V_54 ;
struct V_1 * V_2 = V_45 -> V_55 ;
switch ( V_45 -> V_4 ) {
case 0 :
break;
case - V_7 :
case - V_6 :
case - V_56 :
return;
default:
F_19 ( L_16 , V_45 -> V_4 ) ;
return;
}
F_16 ( V_2 , V_45 ) ;
for ( V_46 = 0 ; V_46 < V_45 -> V_49 ; V_46 ++ ) {
V_45 -> V_50 [ V_46 ] . V_4 = 0 ;
V_45 -> V_50 [ V_46 ] . V_53 = 0 ;
}
V_54 = F_20 ( V_45 , V_57 ) ;
if ( V_54 )
F_19 ( L_17 , V_54 ) ;
}
void F_21 ( struct V_1 * V_2 )
{
int V_46 , V_58 = V_2 -> V_19 . V_58 ;
if ( ! V_58 )
return;
F_15 ( L_18 , V_58 ) ;
for ( V_46 = 0 ; V_46 < V_58 ; V_46 ++ ) {
F_22 ( V_2 -> V_19 . V_45 [ V_46 ] ) ;
}
F_15 ( L_19 ) ;
}
void F_23 ( struct V_1 * V_2 )
{
struct V_45 * V_45 ;
int V_46 , V_58 = V_2 -> V_19 . V_58 ;
F_15 ( L_20 , V_58 ) ;
for ( V_46 = 0 ; V_46 < V_58 ; V_46 ++ ) {
V_45 = V_2 -> V_19 . V_45 [ V_46 ] ;
if ( V_45 ) {
if ( V_2 -> V_19 . V_51 [ V_46 ] ) {
#ifndef F_24
F_25 ( V_2 -> V_59 ,
V_45 -> V_60 ,
V_2 -> V_19 . V_51 [ V_46 ] ,
V_45 -> V_61 ) ;
#else
F_26 ( V_2 -> V_19 . V_51 [ V_46 ] ) ;
#endif
}
F_27 ( V_45 ) ;
V_2 -> V_19 . V_45 [ V_46 ] = NULL ;
}
V_2 -> V_19 . V_51 [ V_46 ] = NULL ;
}
F_26 ( V_2 -> V_19 . V_45 ) ;
F_26 ( V_2 -> V_19 . V_51 ) ;
V_2 -> V_19 . V_45 = NULL ;
V_2 -> V_19 . V_51 = NULL ;
V_2 -> V_19 . V_58 = 0 ;
F_15 ( L_21 ) ;
}
void F_28 ( struct V_1 * V_2 )
{
F_21 ( V_2 ) ;
F_23 ( V_2 ) ;
}
int F_29 ( struct V_1 * V_2 )
{
struct V_45 * V_45 ;
int V_46 , V_62 , V_63 , V_64 , V_65 , V_58 ;
if ( V_2 -> V_19 . V_58 )
F_28 ( V_2 ) ;
F_15 ( L_22 ) ;
V_58 = V_66 ;
V_65 = V_67 ;
V_64 = V_65 * V_2 -> V_68 ;
V_2 -> V_19 . V_17 = NULL ;
V_2 -> V_19 . V_68 = V_2 -> V_68 ;
V_2 -> V_19 . V_45 = F_30 ( sizeof( void * ) * V_58 , V_69 ) ;
if ( ! V_2 -> V_19 . V_45 ) {
F_19 ( L_23 ) ;
return - V_70 ;
}
V_2 -> V_19 . V_51 = F_30 ( sizeof( void * ) * V_58 ,
V_69 ) ;
if ( ! V_2 -> V_19 . V_51 ) {
F_19 ( L_24 ) ;
F_26 ( V_2 -> V_19 . V_45 ) ;
return - V_70 ;
}
for ( V_46 = 0 ; V_46 < V_58 ; V_46 ++ ) {
V_45 = F_31 ( V_65 , V_69 ) ;
if ( ! V_45 ) {
F_19 ( L_25 , V_46 ) ;
goto V_71;
}
V_2 -> V_19 . V_45 [ V_46 ] = V_45 ;
#ifndef F_24
V_2 -> V_19 . V_51 [ V_46 ] = F_32 ( V_2 -> V_59 ,
V_64 , V_69 , & V_45 -> V_61 ) ;
#else
V_2 -> V_19 . V_51 [ V_46 ] = F_33 ( V_64 , V_69 ) ;
#endif
if ( ! V_2 -> V_19 . V_51 [ V_46 ] ) {
F_19 ( L_26 ,
V_64 , V_46 ) ;
if ( V_46 < V_72 )
goto V_71;
goto V_73;
}
memset ( V_2 -> V_19 . V_51 [ V_46 ] , 0 , V_64 ) ;
V_45 -> V_2 = V_2 -> V_59 ;
V_45 -> V_74 = F_34 ( V_2 -> V_59 , V_75 ) ;
V_45 -> V_51 = V_2 -> V_19 . V_51 [ V_46 ] ;
V_45 -> V_60 = V_64 ;
V_45 -> V_76 = F_18 ;
V_45 -> V_55 = V_2 ;
V_45 -> V_77 = 1 ;
V_45 -> V_78 = 0 ;
V_45 -> V_49 = V_65 ;
#ifndef F_24
V_45 -> V_79 = V_80 | V_81 ;
#else
V_45 -> V_79 = V_80 ;
#endif
V_63 = 0 ;
for ( V_62 = 0 ; V_62 < V_65 ; V_62 ++ ) {
V_45 -> V_50 [ V_62 ] . V_52 = V_63 ;
V_45 -> V_50 [ V_62 ] . V_44 =
V_2 -> V_19 . V_68 ;
V_63 += V_2 -> V_19 . V_68 ;
}
}
F_15 ( L_27 , V_58 ) ;
V_2 -> V_19 . V_58 = V_58 ;
return 0 ;
V_73:
F_27 ( V_2 -> V_19 . V_45 [ V_46 ] ) ;
V_2 -> V_19 . V_45 [ V_46 ] = NULL ;
F_17 ( L_28 , V_46 - 1 ) ;
V_2 -> V_19 . V_58 = V_46 - 1 ;
return 0 ;
V_71:
V_2 -> V_19 . V_58 = V_46 + 1 ;
F_23 ( V_2 ) ;
return - V_70 ;
}
