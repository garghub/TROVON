static int F_1 ( unsigned short V_1 , unsigned short V_2 ,
unsigned short V_3 , unsigned short V_4 ,
unsigned short * V_5 , unsigned short * V_6 ,
unsigned short * V_7 , unsigned short * V_8 ,
unsigned short * V_9 , unsigned short * V_10 )
{
unsigned short V_11 = 2 , * V_12 = & V_11 ;
unsigned short V_13 = 3 , * V_14 = & V_13 ;
unsigned short V_15 = 4 , * V_16 = & V_15 ;
unsigned short V_17 = 5 , * V_18 = & V_17 ;
unsigned short V_19 = 6 , * V_20 = & V_19 ;
unsigned short V_21 = 7 , * V_22 = & V_21 ;
unsigned short V_23 = - V_24 , * V_25 = & V_23 ;
unsigned int V_26 = ( V_1 << 16 ) | V_2 ;
unsigned int V_27 = ( V_3 << 16 ) | V_4 ;
int V_28 = 0 ;
F_2 ( V_29 , L_1 ,
V_1 , V_2 , V_3 , V_4 ) ;
__asm__ __volatile__("movw $0x5380,%%ax\n\t"
"movl %7,%%ebx\n\t"
"shrl $16, %%ebx\n\t"
"movw %7,%%cx\n\t"
"movl %8,%%edi\n\t"
"shrl $16,%%edi\n\t"
"movw %8,%%si\n\t"
"movw %9,%%dx\n\t"
"out %%al,%%dx\n\t"
"out %%al,$0x4F\n\t"
"cmpb $0x53,%%ah\n\t"
"je 2f\n\t"
"1:\n\t"
"orb %%ah,%%ah\n\t"
"jnz 2f\n\t"
"movw %%ax,%0\n\t"
"movw %%bx,%1\n\t"
"movw %%cx,%2\n\t"
"movw %%dx,%3\n\t"
"movw %%di,%4\n\t"
"movw %%si,%5\n\t"
"movw $1,%6\n\t"
"2:\n\t":"=m"(*(unsigned short *) pmyoutAX),
"=m"(*(unsigned short *) pmyoutBX),
"=m"(*(unsigned short *) pmyoutCX),
"=m"(*(unsigned short *) pmyoutDX),
"=m"(*(unsigned short *) pmyoutDI),
"=m"(*(unsigned short *) pmyoutSI),
"=m"(*(unsigned short *) pusSmapiOK)
:"m"(inBXCX), "m"(inDISI), "m"(g_usSmapiPort)
:"%eax", "%ebx", "%ecx", "%edx", "%edi",
"%esi");
F_3 ( V_29 ,
L_2 ,
V_11 , V_13 , V_15 , V_17 , V_19 , V_21 ,
V_23 ) ;
* V_5 = V_11 ;
* V_6 = V_13 ;
* V_7 = V_15 ;
* V_8 = V_17 ;
* V_9 = V_19 ;
* V_10 = V_21 ;
V_28 = ( V_23 == 1 ) ? 0 : - V_24 ;
F_4 ( V_29 , L_3 , V_28 ) ;
return V_28 ;
}
int F_5 ( T_1 * V_30 )
{
int V_31 = - V_24 ;
unsigned short V_32 , V_33 , V_34 , V_35 , V_36 , V_37 ;
unsigned short V_38 [] = { 0x0030 , 0x4E30 , 0x8E30 , 0xCE30 , 0x0130 , 0x0350 , 0x0070 , 0x0DB0 } ;
unsigned short V_39 [] = { 0x03F8 , 0x02F8 , 0x03E8 , 0x02E8 } ;
unsigned short V_40 = 8 ;
unsigned short V_41 = 4 ;
F_6 ( V_29 , L_4 ) ;
V_31 = F_1 ( 0x1802 , 0x0000 , 0 , 0 ,
& V_32 , & V_33 , & V_34 , & V_35 , & V_36 , & V_37 ) ;
if ( V_31 ) {
F_7 ( V_42 L_5 ) ;
return V_31 ;
}
F_6 ( V_29 , L_6 ) ;
V_30 -> V_43 = ( ( V_33 & 0x0100 ) != 0 ) ;
V_30 -> V_44 = ( ( V_34 & 0x0001 ) != 0 ) ;
V_30 -> V_45 = V_37 & 0x00FF ;
V_30 -> V_46 = ( V_37 & 0xFF00 ) >> 8 ;
if ( ( V_36 & 0x00FF ) < V_40 ) {
V_30 -> V_47 = V_38 [ V_36 & 0x00FF ] ;
} else {
V_30 -> V_47 = 0 ;
}
F_8 ( V_29 ,
L_7 ,
V_30 -> V_43 , V_30 -> V_44 ,
V_30 -> V_45 , V_30 -> V_46 ,
V_30 -> V_47 ) ;
if ( V_30 -> V_47 == 0 )
F_7 ( V_42 L_8 ) ;
if ( V_30 -> V_45 == 0 )
F_7 ( V_42 L_9 ) ;
V_31 = F_1 ( 0x1804 , 0x0000 , 0 , 0 ,
& V_32 , & V_33 , & V_34 , & V_35 , & V_36 , & V_37 ) ;
if ( V_31 ) {
F_7 ( L_10 ) ;
return V_31 ;
}
F_6 ( V_29 , L_6 ) ;
V_30 -> V_48 = ( ( V_34 & 0x0001 ) != 0 ) ;
V_30 -> V_49 = V_37 & 0x000F ;
if ( ( ( V_37 & 0xFF00 ) >> 8 ) < V_41 ) {
V_30 -> V_50 = V_39 [ ( V_37 & 0xFF00 ) >> 8 ] ;
} else {
V_30 -> V_50 = 0 ;
}
F_9 ( V_29 ,
L_11 ,
V_30 -> V_48 ,
V_30 -> V_49 ,
V_30 -> V_50 ) ;
if ( V_30 -> V_50 == 0 )
F_7 ( V_42 L_12 ) ;
if ( V_30 -> V_49 == 0 )
F_7 ( V_42 L_13 ) ;
F_4 ( V_29 , L_14 , V_31 ) ;
return V_31 ;
}
int F_10 ( void )
{
int V_31 = - V_24 ;
int V_51 ;
unsigned short V_32 , V_33 , V_34 , V_35 , V_36 , V_37 ;
unsigned short V_38 [] = { 0x0030 , 0x4E30 , 0x8E30 , 0xCE30 , 0x0130 , 0x0350 , 0x0070 , 0x0DB0 } ;
unsigned short V_39 [] = { 0x03F8 , 0x02F8 , 0x03E8 , 0x02E8 } ;
unsigned short V_52 [] = { 5 , 7 , 10 , 11 , 15 } ;
unsigned short V_53 [] = { 3 , 4 } ;
unsigned short V_40 = 8 ;
unsigned short V_41 = 4 ;
unsigned short V_54 = 5 ;
unsigned short V_55 = 2 ;
unsigned short V_56 = 0 , V_57 = 0 ;
F_2 ( V_29 ,
L_15 ,
V_58 , V_59 , V_60 , V_61 ) ;
if ( V_59 ) {
for ( V_51 = 0 ; V_51 < V_40 ; V_51 ++ ) {
if ( V_59 == V_38 [ V_51 ] )
break;
}
if ( V_51 == V_40 ) {
F_7 ( V_42 L_16 , V_59 ) ;
return V_31 ;
}
V_56 = V_51 ;
}
if ( V_58 ) {
for ( V_51 = 0 ; V_51 < V_54 ; V_51 ++ ) {
if ( V_58 == V_52 [ V_51 ] )
break;
}
if ( V_51 == V_54 ) {
F_7 ( V_42 L_17 , V_58 ) ;
return V_31 ;
}
}
if ( V_61 ) {
for ( V_51 = 0 ; V_51 < V_41 ; V_51 ++ ) {
if ( V_61 == V_39 [ V_51 ] )
break;
}
if ( V_51 == V_41 ) {
F_7 ( V_42 L_18 , V_61 ) ;
return V_31 ;
}
V_57 = V_51 ;
}
if ( V_60 ) {
for ( V_51 = 0 ; V_51 < V_55 ; V_51 ++ ) {
if ( V_60 == V_53 [ V_51 ] )
break;
}
if ( V_51 == V_55 ) {
F_7 ( V_42 L_19 , V_60 ) ;
return V_31 ;
}
}
if ( V_60 || V_61 ) {
V_31 = F_1 ( 0x1402 , 0x0000 , 0 , 0 ,
& V_32 , & V_33 , & V_34 , & V_35 , & V_36 , & V_37 ) ;
if ( V_31 ) goto V_62;
if ( V_33 & 0x0100 ) {
if ( V_34 & 1 ) {
if ( ( V_37 & 0xFF ) == V_60 ) {
#ifndef F_11
F_7 ( V_42
L_20 , V_37 & 0xFF , V_60 ) ;
#else
F_12 ( V_29 ,
L_20 , V_37 & 0xFF , V_60 ) ;
#endif
#ifdef F_11
F_6 ( V_29 ,
L_21 ) ;
V_31 = F_1 ( 0x1403 , 0x0100 , 0 , V_37 ,
& V_32 , & V_33 , & V_34 , & V_35 , & V_36 , & V_37 ) ;
if ( V_31 ) goto V_62;
V_31 = F_1 ( 0x1402 , 0x0000 , 0 , 0 ,
& V_32 , & V_33 , & V_34 , & V_35 , & V_36 , & V_37 ) ;
if ( V_31 ) goto V_62;
#else
goto V_63;
#endif
} else {
if ( ( V_37 >> 8 ) == V_57 ) {
#ifndef F_11
F_7 ( V_42
L_22 , V_39 [ V_37 >> 8 ] , V_39 [ V_57 ] ) ;
#else
F_12 ( V_29 ,
L_22 , V_39 [ V_37 >> 8 ] , V_39 [ V_57 ] ) ;
#endif
#ifdef F_11
F_6 ( V_29 ,
L_23 ) ;
V_31 = F_1 ( 0x1403 , 0x0100 , 0 , V_37 ,
& V_32 , & V_33 , & V_34 , & V_35 , & V_36 , & V_37 ) ;
if ( V_31 ) goto V_62;
V_31 = F_1 ( 0x1402 , 0x0000 , 0 , 0 ,
& V_32 , & V_33 , & V_34 , & V_35 , & V_36 , & V_37 ) ;
if ( V_31 ) goto V_62;
#else
goto V_63;
#endif
}
}
}
}
V_31 = F_1 ( 0x1404 , 0x0000 , 0 , 0 ,
& V_32 , & V_33 , & V_34 , & V_35 , & V_36 , & V_37 ) ;
if ( V_31 ) goto V_62;
if ( V_33 & 0x0100 ) {
if ( V_34 & 1 ) {
if ( ( V_37 & 0xFF ) == V_60 ) {
#ifndef F_11
F_7 ( V_42
L_24 , V_37 & 0xFF , V_60 ) ;
#else
F_12 ( V_29 ,
L_24 , V_37 & 0xFF , V_60 ) ;
#endif
#ifdef F_11
F_6 ( V_29 ,
L_25 ) ;
V_31 = F_1 ( 0x1405 , 0x0100 , 0 , V_37 ,
& V_32 , & V_33 , & V_34 , & V_35 , & V_36 , & V_37 ) ;
if ( V_31 ) goto V_62;
V_31 = F_1 ( 0x1404 , 0x0000 , 0 , 0 ,
& V_32 , & V_33 , & V_34 , & V_35 , & V_36 , & V_37 ) ;
if ( V_31 ) goto V_62;
#else
goto V_63;
#endif
} else {
if ( ( V_37 >> 8 ) == V_57 ) {
#ifndef F_11
F_7 ( V_42
L_26 , V_39 [ V_37 >> 8 ] , V_39 [ V_57 ] ) ;
#else
F_12 ( V_29 ,
L_26 , V_39 [ V_37 >> 8 ] , V_39 [ V_57 ] ) ;
#endif
#ifdef F_11
F_6 ( V_29 ,
L_25 ) ;
V_31 = F_1 ( 0x1405 , 0x0100 , 0 , V_37 ,
& V_32 , & V_33 , & V_34 , & V_35 , & V_36 , & V_37 ) ;
if ( V_31 ) goto V_62;
V_31 = F_1 ( 0x1404 , 0x0000 , 0 , 0 ,
& V_32 , & V_33 , & V_34 , & V_35 , & V_36 , & V_37 ) ;
if ( V_31 ) goto V_62;
#else
goto V_63;
#endif
}
}
}
}
V_31 = F_1 ( 0x1700 , 0x0000 , 0 , 0 ,
& V_32 , & V_33 , & V_34 , & V_35 , & V_36 , & V_37 ) ;
if ( V_31 ) goto V_62;
V_31 = F_1 ( 0x1704 , 0x0000 , 0 , 0 ,
& V_32 , & V_33 , & V_34 , & V_35 , & V_36 , & V_37 ) ;
if ( V_31 ) goto V_62;
if ( ( V_34 & 0xff ) != 0xff ) {
if ( ( V_34 & 0xff ) == V_60 ) {
#ifndef F_11
F_7 ( V_42
L_27 , V_34 & 0xff , V_60 ) ;
#else
F_12 ( V_29 ,
L_27 , V_34 & 0xff , V_60 ) ;
#endif
#ifdef F_11
F_6 ( V_29 ,
L_28 ) ;
V_31 = F_1 ( 0x1701 , 0x0100 , 0 , 0 ,
& V_32 , & V_33 , & V_34 , & V_35 , & V_36 , & V_37 ) ;
if ( V_31 ) goto V_62;
V_31 = F_1 ( 0x1700 , 0 , 0 , 0 ,
& V_32 , & V_33 , & V_34 , & V_35 , & V_36 , & V_37 ) ;
if ( V_31 ) goto V_62;
V_31 = F_1 ( 0x1705 , 0x01ff , 0 , V_37 ,
& V_32 , & V_33 , & V_34 , & V_35 , & V_36 , & V_37 ) ;
if ( V_31 ) goto V_62;
V_31 = F_1 ( 0x1704 , 0x0000 , 0 , 0 ,
& V_32 , & V_33 , & V_34 , & V_35 , & V_36 , & V_37 ) ;
if ( V_31 ) goto V_62;
#else
goto V_63;
#endif
} else {
if ( ( V_37 & 0xff ) == V_57 ) {
#ifndef F_11
F_7 ( V_42
L_29 , V_39 [ V_37 & 0xff ] , V_39 [ V_57 ] ) ;
#else
F_12 ( V_29 ,
L_29 , V_39 [ V_37 & 0xff ] , V_39 [ V_57 ] ) ;
#endif
#ifdef F_11
F_6 ( V_29 ,
L_28 ) ;
V_31 = F_1 ( 0x1701 , 0x0100 , 0 , 0 ,
& V_32 , & V_33 , & V_34 , & V_35 , & V_36 , & V_37 ) ;
if ( V_31 ) goto V_62;
V_31 = F_1 ( 0x1700 , 0 , 0 , 0 ,
& V_32 , & V_33 , & V_34 , & V_35 , & V_36 , & V_37 ) ;
if ( V_31 ) goto V_62;
V_31 = F_1 ( 0x1705 , 0x01ff , 0 , V_37 ,
& V_32 , & V_33 , & V_34 , & V_35 , & V_36 , & V_37 ) ;
if ( V_31 ) goto V_62;
V_31 = F_1 ( 0x1704 , 0x0000 , 0 , 0 ,
& V_32 , & V_33 , & V_34 , & V_35 , & V_36 , & V_37 ) ;
if ( V_31 ) goto V_62;
#else
goto V_63;
#endif
}
}
}
}
V_31 = F_1 ( 0x1802 , 0x0000 , 0 , 0 ,
& V_32 , & V_33 , & V_34 , & V_35 , & V_36 , & V_37 ) ;
if ( V_31 ) goto V_62;
if ( V_59 ) {
V_36 = V_56 ;
}
if ( V_58 ) {
V_37 = ( V_37 & 0xff00 ) | V_58 ;
}
V_31 = F_1 ( 0x1803 , 0x0101 , V_36 , V_37 ,
& V_32 , & V_33 , & V_34 , & V_35 , & V_36 , & V_37 ) ;
if ( V_31 ) goto V_62;
V_31 = F_1 ( 0x1804 , 0x0000 , 0 , 0 ,
& V_32 , & V_33 , & V_34 , & V_35 , & V_36 , & V_37 ) ;
if ( V_31 ) goto V_62;
if ( V_61 ) {
V_37 = ( V_37 & 0x00ff ) | ( V_57 << 8 ) ;
}
if ( V_60 ) {
V_37 = ( V_37 & 0xff00 ) | V_60 ;
}
V_31 = F_1 ( 0x1805 , 0x0101 , 0 , V_37 ,
& V_32 , & V_33 , & V_34 , & V_35 , & V_36 , & V_37 ) ;
if ( V_31 ) goto V_62;
V_31 = F_1 ( 0x1802 , 0x0000 , 0 , 0 ,
& V_32 , & V_33 , & V_34 , & V_35 , & V_36 , & V_37 ) ;
if ( V_31 ) goto V_62;
V_31 = F_1 ( 0x1804 , 0x0000 , 0 , 0 ,
& V_32 , & V_33 , & V_34 , & V_35 , & V_36 , & V_37 ) ;
if ( V_31 ) goto V_62;
F_6 ( V_29 , L_30 ) ;
return 0 ;
V_63:
return - V_24 ;
V_62:
F_7 ( V_42 L_31 , V_31 ) ;
return V_31 ;
}
int F_13 ( BOOLEAN V_64 )
{
int V_31 = - V_24 ;
unsigned short V_32 , V_33 , V_34 , V_35 , V_36 , V_37 ;
unsigned short V_65 ;
F_4 ( V_29 , L_32 , V_64 ) ;
V_65 = ( V_64 ) ? 1 : 0 ;
V_31 = F_1 ( 0x4901 , 0x0000 , 0 , V_65 ,
& V_32 , & V_33 , & V_34 , & V_35 , & V_36 , & V_37 ) ;
F_4 ( V_29 , L_33 , V_31 ) ;
return V_31 ;
}
int F_14 ( void )
{
int V_28 = - V_24 ;
unsigned short V_66 = 0 ;
unsigned long V_67 ;
F_6 ( V_29 , L_34 ) ;
F_15 ( & V_68 , V_67 ) ;
V_66 = F_16 ( 0x7C ) ;
V_66 |= ( F_16 ( 0x7D ) << 8 ) ;
F_17 ( & V_68 , V_67 ) ;
F_4 ( V_29 , L_35 , V_66 ) ;
if ( V_66 == 0x5349 ) {
F_15 ( & V_68 , V_67 ) ;
V_69 = F_16 ( 0x7E ) ;
V_69 |= ( F_16 ( 0x7F ) << 8 ) ;
F_17 ( & V_68 , V_67 ) ;
if ( V_69 == 0 ) {
F_7 ( L_36 ) ;
} else {
F_4 ( V_29 ,
L_37 ,
V_69 ) ;
V_28 = 0 ;
}
} else {
F_7 ( L_38 ) ;
V_28 = - V_70 ;
}
return V_28 ;
}
